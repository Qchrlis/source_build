#ifndef CAPTURE_HANDLE_H
#define CAPTURE_HANDLE_H

#include"recognize_option.h"


class CaptureHandle
{
private:
    const std::vector<std::string> &m_arguments;
    RecognizeOption m_parser;

    int32_t load_compiler_config();
public:
    CaptureHandle(const std::vector<std::string> &args);
    int32_t record_and_rrecognize();
};

#endif // CAPTURE_HANDLE_H
