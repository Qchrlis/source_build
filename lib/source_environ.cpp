#include"source_environ.h"


const std::string BuilderEnviron::updateEnvironByKey(std::string &key, std::string &value)
{
  std::string ret;
  std::unordered_map<std::string, std::string>::iterator iter = environ.find(key);
  if (iter != environ.end()) {
    ret = iter->second;
  }
  environ[key] = value;
  return ret;
}


std::string BuilderEnviron::getEnvironByKey(std::string &key)
{
  std::string ret;
  std::unordered_map<std::string, std::string>::iterator iter = environ.find(key);
  if (iter != environ.end()) {
    ret = iter->second;
  }
  return ret;
}


const std::string BuilderEnviron::removeEnvironByKey(std::string &key)
{
  std::string ret;
  std::unordered_map<std::string, std::string>::iterator iter = environ.find(key);
  if (iter != environ.end()) {
    ret = iter->second;
    environ.erase(iter);
  }
  return ret;
}
