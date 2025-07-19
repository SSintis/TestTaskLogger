#include "../Logger/Logger.hpp"

int main(){
  Logger log("log.txt", LoggerPriority::DEBUG);
  log.newLog("test log", LoggerPriority::INFO);

  log.setNewPriority(LoggerPriority::ERROR);
  log.newLog("qwe", LoggerPriority::INFO);
}

