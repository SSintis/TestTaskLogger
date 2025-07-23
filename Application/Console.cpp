#include "Console.hpp"
#include <iostream>
#include <string>
#include <map>

LoggerPriority Console::getLogger(const std::string& level){
  static const std::map<std::string, LoggerPriority> commands = {
    {"debug", LoggerPriority::DEBUG},
    {"info", LoggerPriority::INFO},
    {"error", LoggerPriority::ERROR}
  };

  auto it = commands.find(level);
  if(it != commands.end()){ return it->second; }
  else { return LoggerPriority::UNKNOWN; }
}

LoggerPriority Console::setPriority(){
  std::string level;

  std::cout << "(write new priority: debug, info, error) -> ";
  std::getline(std::cin, level);

  return getLogger(level);
}

message Console::WaitNewMessage(){
  message log;

  std::string level;

  std::cout << "(message) -> ";
  std::getline(std::cin, log.message);

  std::cout << "(debug, info, error) -> ";
  std::getline(std::cin, level);

  log.level = getLogger(level);

  return log;
}

command Console::WaitCommands(){
  static const std::map<std::string, command> commands = {
    {"exit", command::EXIT},
    {"snp", command::SETNEWDEFAULTPRIORITY},
    {"nlog", command::NEWLOG},
    {"help", command::HELP}
  };

  std::string com;

  std::cout << "-> ";
  std::getline(std::cin, com);

  auto it = commands.find(com);
  if(it != commands.end()){
    return it->second;
  } else {
    return command::EMPTY;
  }
}

void Console::help() {
    std::cout << "\n=== Logger App Help ===\n";
    std::cout << "Available commands:\n\n";
    
    std::cout << "exit - Exit the application\n";
    std::cout << "  Usage: Just type 'exit' to quit\n\n";
    
    std::cout << "snp (Set New Priority) - Change the default log level filter\n";
    std::cout << "  Usage: snp -> then enter one of: debug, info, error\n";
    std::cout << "  Effect: Messages below this level won't be logged\n\n";
    
    std::cout << "nlog (New Log) - Create a new log entry\n";
    std::cout << "  Usage: nlog -> enter message -> select level (debug/info/error)\n";
    std::cout << "  Example:\n";
    std::cout << "    -> nlog\n";
    std::cout << "    (message) -> Server started\n";
    std::cout << "    (debug, info, error) -> info\n\n";
    
    std::cout << "help - Display this help message\n";
    std::cout << "  Usage: help\n\n";
    
    std::cout << "Note: Logs are saved to the file specified at startup\n";
    std::cout << "======================================\n\n";
}
