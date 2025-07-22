#include "../Logger/Logger.hpp"
#include "Console.hpp"

int main(){
  Console console;
  Logger log("log.txt", LoggerPriority::DEBUG);

  int i = 0;
  while(i < 4){
    message newMessage = console.WaitNewMessage();
    log.newLog(newMessage.message, newMessage.level); 
  
    i++;
  }
}
