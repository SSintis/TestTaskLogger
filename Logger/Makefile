# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -fPIC

# Имена файлов
LIB_NAME = libLogger.so
TEST_EXE = Test

# Цели
all: $(LIB_NAME) $(TEST_EXE)

# Сборка динамической библиотеки
$(LIB_NAME): Logger.cpp Logger.hpp
	$(CXX) $(CXXFLAGS) -shared $< -o $@

# Сборка тестовой программы
$(TEST_EXE): Test.cpp $(LIB_NAME)
	$(CXX) $(CXXFLAGS) $< -L. -lLogger -o $@ -Wl,-rpath=.

# Очистка
clean:
	rm -f $(LIB_NAME) $(TEST_EXE)
