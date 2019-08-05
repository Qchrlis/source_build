#include "thread_pool.h"
#include <unistd.h>

ThreadPool::ThreadPool(int32_t size)
  : m_pool_size(size)
{
  m_idle_count = 0;
  m_stop_flag = false;
  m_force_stop = false;
}

int32_t ThreadPool::init_thread_pool()
{
  for (int32_t i =0; i < m_pool_size; i++) {
    pthread_t pthread_id;
    int err = pthread_create(&pthread_id, nullptr, thread_entry, this);
    if (err != 0) {
      terminate_thread_pool();
      return 1;
    }
    m_thread_pool.push_back(pthread_id);
  }
  return 0;
}

int32_t ThreadPool::terminate_thread_pool()
{

  m_force_stop = true;
  join_thread_pool();
  return 0;
}

int32_t ThreadPool::join_thread_pool()
{
  m_stop_flag = true;
  for (auto ntid : m_thread_pool) {
    pthread_join(ntid, nullptr);
  }
  m_thread_pool.clear();
  return 0;
}

void *ThreadPool::thread_entry(void *pdata)
{
  ThreadPool *data = static_cast<ThreadPool *>(pdata);
  std::queue<ThreadTask> task_queue = data->m_task_queue;
  std::queue<ThreadTask> finish_queue = data->m_fin_queue;

  while (!data->m_stop_flag) {
    if (!data->m_force_stop)
      return nullptr;

    ThreadTask *ptask = nullptr;
    pthread_mutex_lock(&data->m_mutex);
    if (0 == task_queue.size()) {
      pthread_mutex_unlock(&data->m_mutex);
      usleep(50);
      continue;
    }
    *ptask = task_queue.front();
    task_queue.pop();
    pthread_mutex_unlock(&data->m_mutex);

    if (!data->m_force_stop)
      return nullptr;
    int32_t err = ptask->run();
    if (0 != err) {
      ptask->set_task_st(ThreadTask::TASK_STATUS_ERROR);
    } else {
      ptask->set_task_st(ThreadTask::TASK_STATUS_ZERO);
    }
    if (!data->m_force_stop)
      return nullptr;
    pthread_mutex_lock(&data->m_mutex);
    finish_queue.push(*ptask);
    pthread_mutex_unlock(&data->m_mutex);
  }
  return nullptr;
}
