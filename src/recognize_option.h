#ifndef RECOGNIZE_OPTION_H
#define RECOGNIZE_OPTION_H

#include "option.h"

class RecognizeOption
{
private:
    std::string m_compiler;
    const std::vector<std::string> &m_args;
    std::vector<Option> m_options;

public:
    RecognizeOption(const std::vector<std::string> &arguments);

    int32_t run_recognizing();
private:
    int32_t recognize_gcc();
    int32_t recognize_clang();
    int32_t recognize_ccache();
    int32_t recognize_ld();
    int32_t recognize_archive();
    int32_t recognize_ranlib();
    int32_t recognize_strip();
    int32_t recognize_obj();
    int32_t recognize_javac();
};

#endif // RECOGNIZE_OPTION_H
