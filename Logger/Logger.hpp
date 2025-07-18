#pragma once

#include <fstream>
#include <string>

enum class LoggerPriority{
  DEBUG,
  INFO,
  ERRROR 
};

class Logger{
public:
  Logger(const std::string& filename, const LoggerPriority prioriry);

private:
  std::ofstream file;
  LoggerPriority defaultPriority;
};
