#ifndef OPTION_H
#define OPTION_H

#include"opt_type.h"
#include<vector>
#include<string>
#include<stdint.h>


class Option
{
private:
    OptType m_opt_type;    // Option prefix type.
    OptMatch m_opt_match;  // Option match type.
    OptStatus m_opt_st;    // Option process status.

    std::string m_option;  // Option value, like -c -> c
    std::vector<std::string> m_params;  // Option values.
    std::vector<std::string> m_alias;   // Option alias

    OptCategory m_category;   // Command type.

public:
    Option(OptCategory category, OptType type, OptMatch match,
           const std::string &option, const std::vector<std::string> &values);

};

#endif // OPTION_H
