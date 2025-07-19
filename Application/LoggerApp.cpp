#include "../Logger/Logger.hpp"

int main(){
  Logger log("log.txt", LoggerPriority::DEBUG);
  log.newLog("geylog", LoggerPriority::INFO);
}
