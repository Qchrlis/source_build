#ifndef LOGGER_H
#define LOGGER_H

#include<plog/Log.h>
#include<pthread.h>
#include<string>
#include<stdint.h>
#include<vector>

class Logger
{
public:
  enum Level{
    LOG_LEVEL_CRITICAL = 0,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_INFO,
    LOG_LEVEL_DEBUG
  };

private:
  Logger();
  ~Logger() {}
  Logger(const Logger& l) {}
  Logger& operator= (const Logger& l) {}

  Level m_log_level;
  bool m_log_term;
  std::vector<std::string> m_log_handle;
  std::vector<std::string> m_log_message;

  static Logger * m_instance;
  static pthread_mutex_t mutex;

public:
  static Logger *getInstance() {
    pthread_mutex_lock(&mutex);
    if (m_instance == nullptr) {
      m_instance = new Logger();
    }
    pthread_mutex_unlock(&mutex);
    return m_instance;
  }

  void add_log_handle(std::string file_path);
  void enable_log_term();
  void log_detail(Level level, const std::string _file_, const std::string _function_, int32_t _line_, char *message);
};

#endif // LOGGER_H
