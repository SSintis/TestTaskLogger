# Имя исполняемого файла
TARGET = my_program

# Пути
LIB_DIR = ../Logger
INC_DIR = ../Logger       # Путь к Logger.hpp
LIB_NAME = Logger

# Исходные файлы
SRC = LoggerApp.cpp

# Компилятор
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INC_DIR)  # Добавляем путь к инклюдам

# Флаги линковки
LDFLAGS = -L$(LIB_DIR) -l$(LIB_NAME) -Wl,-rpath=$(LIB_DIR)

# Правило по умолчанию
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TARGET)

.PHONY: all clean run
