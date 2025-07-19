CXX = g++
CXXFLAGS = -std=c++17 -Wall -fPIC

LIB_NAME = libLogger.so

all: $(LIB_NAME) $(TEST_EXE)

$(LIB_NAME): Logger.cpp Logger.hpp
	$(CXX) $(CXXFLAGS) -shared $< -o $@

clean:
	rm -f $(LIB_NAME) $(TEST_EXE)
