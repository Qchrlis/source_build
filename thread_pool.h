#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include"thread_task.h"
#include<pthread.h>
#include<vector>
#include<queue>
#include<string>

class ThreadPool
{
private:
    const int32_t m_pool_size;
    int32_t m_idle_count;
    int32_t m_stop_flag;
    int32_t m_force_stop;

    std::vector<pthread_t> m_thread_pool;

    pthread_mutex_t m_mutex;
    std::queue<ThreadTask> m_task_queue;
    std::queue<ThreadTask> m_fin_queue;
public:
    ThreadPool(int32_t size);

    int32_t init_thread_pool();
    int32_t terminate_thread_pool();
    int32_t join_thread_pool();

    bool is_idle() { m_thread_pool.size() == m_idel_pool.size(); };
    bool is_full() { 0 == m_idel_pool.size(); };

    static void *thread_entry(void *pdata);
};

#endif // THREAD_POOL_H
