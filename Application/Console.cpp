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

void Console::help(){
  std::cout << "---help---\n";
  std::cout << "exit - \n";
  std::cout << "snp - set new default priority\n";
  std::cout << "nlog - new log\n";
  std::cout << "help - show all commands\n";
}
