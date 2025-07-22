#include "Console.hpp"
#include <iostream>
#include <string>
#include <map>

message Console::WaitNewMessage(){
  message log;

  std::string level;

  std::cout << "(message) -> ";
  std::getline(std::cin, log.message);

  std::cout << "(debug, info, error) -> ";
  std::getline(std::cin, level);

  static const std::map<std::string, LoggerPriority> commands = {
    {"debug", LoggerPriority::DEBUG},
    {"info",  LoggerPriority::INFO},
    {"error",  LoggerPriority::ERROR}
  };

  auto it = commands.find(level);
  if (it != commands.end()) {
    log.level = it->second; 
  } else {
    log.level = LoggerPriority::UNKNOWN;
  }

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
