# C++ compiler
CXX=g++

# Compiler flags
CXXFLAGS=-std=c++11 -Wall

# Targets
all: first second third

# Build first program
first: first.cpp
	$(CXX) $(CXXFLAGS) first.cpp -o first.o

# Build second program
second: second.cpp
	$(CXX) $(CXXFLAGS) second.cpp -o second.o

# Build third program
third: third.cpp
	$(CXX) $(CXXFLAGS) third.cpp -o third.o

# Clean up
clean:
	rm -f *.o
