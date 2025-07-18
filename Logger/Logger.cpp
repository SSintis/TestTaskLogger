#include "Logger.hpp"
#include <iostream>

Logger::Logger(const std::string& filename, const LoggerPriority priority){
  this->defaultPriority = priority;
  file.open(filename);

  if(!file.is_open()){ std::cerr << "LOGGER ERROR: incorrect filename path."; }
}
