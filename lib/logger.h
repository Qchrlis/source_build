#ifndef LOGGER_H
#define LOGGER_H

#include<pthread.h>
#include<string>
#include<stdint.h>
#include<queue>
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

  std::string m_file_path;
  bool m_enable_term;
  Level m_level;
  long m_maxsize;
  long m_chunksize;
  long m_rotate_count;

  std::queue<std::string> m_messages;
  std::vector<std::string> m_log_handle;

  static Logger * m_instance;
  static pthread_mutex_t m_mutex;
  static pthread_mutex_t m_mutex;

public:
  static Logger *getInstance() {
    pthread_mutex_lock(&m_mutex);
    if (m_instance == nullptr) {
      m_instance = new Logger();
    }
    pthread_mutex_unlock(&m_mutex);
    return m_instance;
  }

  void add_log_handle(std::string file_path);
  void enable_log_terminal() { m_term = true; }
  void set_log_level(Level level) { m_level = level; }
  void set_log_maxsize(long max_size) {}
  void set_log_rotate_count(int count);
  void set_log_chunksize(long chunk_size);
  void log_detail(Level level, const std::string _file_, const std::string _function_, int32_t _line_, char *message);
};

#endif // LOGGER_H
