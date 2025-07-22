#include "Logger.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>

Logger::Logger(const std::string& filename, const LoggerPriority priority) : defaultPriority(priority), filename(filename){
  file.open(filename, std::ofstream::out | std::ofstream::app);
  
  if(!file.is_open()) throw std::runtime_error("Logger: Failed to open file: " + filename);
}

void Logger::newLog(const std::string& message, const LoggerPriority priority){
  time_t now = time(nullptr);
  tm *tm_now = localtime(&now);
  
  std::stringstream ss;
  ss << std::put_time(tm_now, "%H:%M:%S");
  
  if(priority >= defaultPriority){
    if(!file.is_open()){
      file.open(this->filename, std::ofstream::out | std::ofstream::app);
    }

    std::string formatedMessage = "[" + levelToString(priority) + "] " + ss.str() + " - " + message + "\n";
    file.write(formatedMessage.data(), formatedMessage.size());
    file.flush();

    file.close();
  }
}

std::string Logger::levelToString(LoggerPriority level){
  switch (level) {
    case LoggerPriority::DEBUG: return "DEBUG";
    case LoggerPriority::INFO:  return "INFO";
    case LoggerPriority::ERROR: return "ERROR";
    case LoggerPriority::UNKNOWN: return levelToString(this->defaultPriority);
  };
  return levelToString(this->defaultPriority);
}

void Logger::setNewPriority(const LoggerPriority newPriority){
  defaultPriority = newPriority;
}
