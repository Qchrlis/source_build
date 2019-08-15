#include"source_manager.h"

SourceFile::SourceFile(const std::string &file, const std::string &dir, const std::string &encode)
  :fileName(file), dirPath(dir), encoding(encode)
{
}
