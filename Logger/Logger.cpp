#include "Logger.hpp"
#include <ctime>
#include <iomanip>
#include <stdexcept>

Logger::Logger(const std::string& filename, const LoggerPriority priority) : defaultPriority(priority), filename(filename){
  file.open(filename);
  
  if(!file.is_open()) throw std::runtime_error("Logger: Failed to open file: " + filename);
}

void Logger::newLog(const std::string& message, const LoggerPriority priority){
  time_t now = time(nullptr);
  tm *tm_now = localtime(&now);
  
  std::stringstream ss;
  ss << std::put_time(tm_now, "%H:%M:%S");
  
  if(priority >= defaultPriority){
    if(!file.is_open()){
      file.open(this->filename);
    }

    std::string formatedMessage = "[" + levelToString(priority) + "] " + ss.str() + " - " + message + "\n";
    file.write(formatedMessage.data(), formatedMessage.size());
  }
}

std::string Logger::levelToString(LoggerPriority level){
  switch (level) {
    case LoggerPriority::DEBUG: return "DEBUG";
    case LoggerPriority::INFO:  return "INFO";
    case LoggerPriority::ERROR:return "ERROR";
  };
  return "INFO";
}

void Logger::setNewPriority(const LoggerPriority newPriority){
  defaultPriority = newPriority;
}
