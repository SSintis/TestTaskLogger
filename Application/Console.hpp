#pragma once

#include <string>
#include "../Logger/Logger.hpp"

struct message{
  std::string message;
  LoggerPriority level; 
};

enum class command{
  EXIT,
  NEWLOG,
  SETNEWDEFAULTPRIORITY,
  HELP,
  EMPTY
};

class Console{
public:
  message WaitNewMessage();
  command WaitCommands();
  void help();
  LoggerPriority setPriority();

private:
  LoggerPriority getLogger(const std::string& level);
};
