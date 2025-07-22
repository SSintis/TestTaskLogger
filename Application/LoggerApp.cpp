#include "../Logger/Logger.hpp"
#include "Console.hpp"

int main(){
  Console console;
  Logger log("log.txt", LoggerPriority::DEBUG);

  while(true){
    command commands = console.WaitCommands();

    switch (commands) {
      case command::NEWLOG: {
        message mes = console.WaitNewMessage(); 
        log.newLog(mes.message, mes.level);

        break;
      }
      case command::SETNEWDEFAULTPRIORITY:
      case command::EXIT: return 0;
      case command::HELP: console.help(); break;
      case command::EMPTY: break;
    }
  }
}
