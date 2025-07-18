#pragma once

#include <fstream>
#include <string>

enum class LoggerPriority{
  DEBUG,
  INFO,
  ERROR 
};

class Logger{
public:
  Logger(const std::string& filename, const LoggerPriority prioriry);
  void newLog(const std::string& message, const LoggerPriority prioriry);
  void setNewPriority(const LoggerPriority newPriority);

private:
  std::ofstream file;
  LoggerPriority defaultPriority;
  std::string filename;

  std::string levelToString(LoggerPriority level);
};
