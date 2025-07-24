# Logger & example application

Эта страница для тестового задание на позицию 'Стажер Разработчик С++' компании infotecs.

Logger - библиотека для записи логов в указанный файл с тремя уровнями важности [debug, info, error].
Application - тестовое приложение, цель которого продемонстрировать все возможности библиотеки Logger.

## Особености

 - **Многопоточность** записи логов в файл
 - **Три уровня логирования**: DEBUG, INFO, ERROR
 - **Простое** управление через консольное приложение

## Требования

 - C++17
 - Linux
 - Компилятор g++

# Использование библиотеки:

После компиляции libLogger.so файл, можно добавить Logger.hpp в стандартные пути поиска библиотек командой:

```bash
sudo cd Logger/Logger.hpp /usr/local/include/
```

## Подключение библиотеки

```cpp
#include <Logger.hpp>
```

## Создание экземпляра 

```cpp
Logger log(filename, default priority);
```

## Запись нового лога

```cpp
log.newLog("message", LoggerPriority::INFO);
```

# Консольное приложение
## Запуск

```bash
cd Application/
./loggerapp <log_file> [default_priority]
```

## Пример

```bash
./loggerapp log.txt info
```

## Доступные команды:

 - "help" показать все команды 
 - "snp" изменить приоритет по умолчанию
 - "nlog" создать новую запись в логе 
 - "exit" закрыть программу

# Структура лог файла

```test
[INFO] 14:30:45 - File create
[ERROR] 14:31:32 - File close
```
