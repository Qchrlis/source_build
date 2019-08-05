

set(OBJSRC
  thread_pool.cpp
  thread_task.cpp
  exec_process.cpp)


add_library(utils STATIC ${OBJSRC})
