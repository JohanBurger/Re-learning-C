CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

PROGRAMS := checked_int colourful comma_operator free_store point trainwreck

.PHONY: all clean

all: $(PROGRAMS)

checked_int: checked_int.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

colourful: colourful.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

comma_operator: comma_operator.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

free_store: free_store.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

point: point.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

trainwreck: trainwreck.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(PROGRAMS)