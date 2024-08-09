# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable name
TARGET = my_program

# Source files
SRCS = main.cpp bank.cpp

# Object files (derived from SRCS)
OBJS = $(SRCS:.cpp=.o)

# Header files
DEPS = bank.h

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)
