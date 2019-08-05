#include "recognize_option.h"

RecognizeOption::RecognizeOption(const std::vector<std::string> &arguments)
  : m_args(arguments)
{
  m_compiler = arguments.front();
}
