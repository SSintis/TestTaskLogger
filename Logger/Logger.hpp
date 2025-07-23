#pragma once

#include <fstream>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

enum class LoggerPriority{
  DEBUG,
  INFO,
  ERROR, 
  UNKNOWN
};

class Logger{
public:
  Logger(const std::string& filename, const LoggerPriority priority);
  ~Logger();
  void newLog(const std::string& message, const LoggerPriority priority);
  void setNewPriority(const LoggerPriority newPriority);

private:
  std::ofstream file;
  LoggerPriority defaultPriority;
  std::string filename;

  std::string levelToString(LoggerPriority level);
  void writeLoop();

  std::queue<std::string> logQueue; 
  std::mutex queueMutex; 
  std::condition_variable cv;
  std::thread writerThread;
  bool running = true; 
};
