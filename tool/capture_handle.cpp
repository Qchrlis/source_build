#include "capture_handle.h"

CaptureHandle::CaptureHandle(const std::vector<std::string> &args)
  : m_arguments(args), m_parser(args)
{
}

int32_t CaptureHandle::record_and_rrecognize()
{
  int32_t status = load_compiler_config();
  if (status) {
    return 1;
  }

  return 0;
}















