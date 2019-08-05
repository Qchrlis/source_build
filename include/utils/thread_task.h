#ifndef THREAD_TASK_H
#define THREAD_TASK_H

#include<string>

class ThreadTask
{
public:
    enum TaskStatus {
        TASK_STATUS_ZERO = 0,
        TASK_STATUS_ERROR,
        TASK_STATUS_PARAM,
        TASK_STATUS_OTHER,
    };
    ThreadTask();

    int32_t run();
    void set_task_st(TaskStatus st) { m_task_st = st; }
    TaskStatus get_task_st(TaskStatus st) { return m_task_st; }

private:
    TaskStatus m_task_st;

};

#endif // THREAD_TASK_H
