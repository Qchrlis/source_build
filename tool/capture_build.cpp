#include<plog/Log.h>
#include <iostream>

using namespace std;

int main()
{
  plog::init(plog::info, "capture.log");


  PLOGD << "This is a debug log.";
  PLOGE << "This is a error log.";
  PLOGF << "This is a fatal log.";
  PLOGV << "This is a verbose log.";
  return 0;
}
