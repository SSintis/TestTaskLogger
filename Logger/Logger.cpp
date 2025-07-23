#include "Logger.hpp"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <thread>
#include <iostream>

Logger::Logger(const std::string& filename, const LoggerPriority priority) : defaultPriority(priority), filename(filename){
  writerThread = std::thread(&Logger::writeLoop, this);
}

void Logger::newLog(const std::string& message, const LoggerPriority priority){
  if(priority < defaultPriority) return;

  time_t now = time(nullptr);
  tm *tm_now = localtime(&now);
  
  std::stringstream ss;
  ss << std::put_time(tm_now, "%H:%M:%S");
  
  if(!file.is_open()){
    file.open(this->filename, std::ofstream::out | std::ofstream::app);
  }

  std::string formatedMessage = "[" + levelToString(priority) + "] " + ss.str() + " - " + message;
  
  {
    std::lock_guard<std::mutex> lock(queueMutex);
    logQueue.push(formatedMessage);
  }
  cv.notify_one();
}

void Logger::writeLoop(){
  std::ofstream file(filename, std::ofstream::app);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open log file");
  }

  while (running) {
    std::unique_lock<std::mutex> lock(queueMutex);
    
    cv.wait(lock, [this]() { 
      return !logQueue.empty() || !running; 
    });

    if (!logQueue.empty()) {
      std::string msg = logQueue.front();
      logQueue.pop();
      lock.unlock();

      file << msg << std::endl;
      file.flush();
    }
  }

  file.close();
}

std::string Logger::levelToString(LoggerPriority level){
  switch (level) {
    case LoggerPriority::DEBUG: return "DEBUG";
    case LoggerPriority::INFO:  return "INFO";
    case LoggerPriority::ERROR: return "ERROR";
    case LoggerPriority::UNKNOWN: return levelToString(this->defaultPriority);
  };
  return levelToString(this->defaultPriority);
}

void Logger::setNewPriority(const LoggerPriority newPriority){
  defaultPriority = newPriority;
}

Logger::~Logger() {
  {
    std::lock_guard<std::mutex> lock(queueMutex);
    running = false;  // Говорим потоку остановиться
  }
  cv.notify_all();      // Будим поток, если он спит
  if (writerThread.joinable()) {
    try {
      if (writerThread.get_id() != std::this_thread::get_id()) {
        writerThread.join();
      } else {
        writerThread.detach();
      }
    } catch (const std::system_error& e) {
      std::cerr << "Thread join error: " << e.what() << std::endl;
    }
  }
}
