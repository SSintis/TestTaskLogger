#include "Logger.hpp"
#include <iostream>
#include <ctime>

Logger::Logger(const std::string& filename, const LoggerPriority priority){
  this->defaultPriority = priority;
  file.open(filename);

  if(file.is_open()) this->filename = filename;
  else std::cerr << "ERROR WITH LOGGER: incorrect filename." << std::endl;
}

void Logger::newLog(const std::string& message, const LoggerPriority priority){
  time_t seconds = time(NULL);
  tm* timeinfo = localtime(&seconds);
  std::cout<<"Текущее время и дата:"<<asctime(timeinfo)<<std::endl;

  if(priority >= defaultPriority){
    if(!file.is_open()){
      file.open(this->filename);
    }

    std::string formatedMessage = "[" + levelToString(priority) + "] " + message + "\n";
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
