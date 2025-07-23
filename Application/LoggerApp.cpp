#include "../Logger/Logger.hpp"
#include "Console.hpp"
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[]){
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <log_file> [default_priority]" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  LoggerPriority defaultPriority = LoggerPriority::DEBUG;

  Console console;
  
  if (argc > 2) {
    LoggerPriority argPriority = console.getLogger(argv[2]);
    if (argPriority != LoggerPriority::UNKNOWN) {
      defaultPriority = argPriority;
    }
  }
  
  try{
    Logger log(filename, defaultPriority);
    bool exit = 0;

    while(!exit){
      command commands = console.WaitCommands();

      switch (commands) {
        case command::NEWLOG: {
          message mes = console.WaitNewMessage(); 
          log.newLog(mes.message, mes.level);

          break;
        }
        case command::SETNEWDEFAULTPRIORITY:{
          log.setNewPriority(console.setPriority());
          break;
        }
        case command::EXIT: exit = 1; break;
        case command::HELP: console.help(); break;
        case command::EMPTY: break;
      }
    }
  }
  catch(const std::runtime_error& e){
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
