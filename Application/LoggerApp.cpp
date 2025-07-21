#include "../Logger/Logger.hpp"
#include "Console.hpp"

int main(){
  Console console;
  Logger log("log.txt", LoggerPriority::DEBUG);

  while(true){
    message newMessage = console.WaitNewMessage();
    log.newLog(newMessage.message, newMessage.level); 
  }
}
