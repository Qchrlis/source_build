#pragma once

#include <utility>
#include<string>
#include<unordered_map>

class BuilderEnviron {
private:
  std::string workDir;
  std::string userName;
  std::string machineName;
  std::string curWorkDir;
  std::unordered_map<std::string, std::string> environ;

public:
  BuilderEnviron();
  ~BuilderEnviron();

  const std::string &getworkDir() { return workDir; }
  void setWorkDir(const std::string &dir) { workDir = dir; }
  const std::string &getCurWorkDir() { return curWorkDir; }
  void setCurWorkDir(const std::string &dir) { curWorkDir = dir; }
  const std::string &getMachineName() { return machineName; }
  void setMachineName(const std::string &name) { machineName = name; }
  const std::string &getUserName() { return userName; }
  void setUserName(const std::string &name) { userName = name; }
  const std::unordered_map<std::string, std::string> &getEnviron() {return environ; }
  void setEnviron(const std::unordered_map<std::string, std::string> &env) { environ = env; }

  const std::string updateEnvironByKey(std::string &key, std::string &value);
  std::string getEnvironByKey(std::string &key);
  const std::string removeEnvironByKey(std::string &key);
};
