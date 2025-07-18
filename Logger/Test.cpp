#include "Logger.hpp"
#include <string>

int main(){
  std::string name = "log.txt";
  Logger log(name, LoggerPriority::ERROR);

  std::string message = "eq";
  log.newLog(message, LoggerPriority::ERROR);

  log.newLog("das", LoggerPriority::INFO);
}
