CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

PROGRAMS := auto variadic func_pointers func_types lambda generic_lambda functions example

.PHONY: all clean

all: $(PROGRAMS)

auto: auto.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

variadic: variadic.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

func_pointers: func_pointers.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

func_types: func_types.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

lambda: lambda.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

generic_lambda: generic_lambda.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

functions: functions.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

example: example.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(PROGRAMS)
