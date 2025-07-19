TARGET = loggerapp

LIB_DIR = ../Logger
INC_DIR = ../Logger
LIB_NAME = Logger

SRC = LoggerApp.cpp

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INC_DIR)

LDFLAGS = -L$(LIB_DIR) -l$(LIB_NAME) -Wl,-rpath=$(LIB_DIR)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	LD_LIBRARY_PATH=$(LIB_DIR) ./$(TARGET)

.PHONY: all clean run
