#include "option.h"

Option::Option(OptCategory category, OptType type, OptMatch match,
               const std::string &option, const std::vector<std::string> &values):
   m_opt_type(type), m_opt_match(match), m_option(option), m_params(values),
   m_category(category)
{
}
