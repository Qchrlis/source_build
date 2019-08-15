#pragma once
#include<string>



class SourceFile {
private:
  bool isSymbolic;
  std::string fileName;
  std::string realPath;
  std::string normalPath;
  std::string dirPath;
  std::string encoding;

public:
  SourceFile(const std::string &file, const std::string &dir, const std::string &encode="utf-8");
  virtual ~SourceFile();

  void updateEncoding(const std::string &encode) { encoding=encode; }
  const std::string getEncoding() { return encoding; }
  const std::string getFileName() { return fileName; }
  const std::string getRelativePath() { return relativePath; }
};


class BuilderSourceManager {

};
