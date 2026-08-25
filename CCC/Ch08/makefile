CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

PROGRAMS := constexpr_if fibonacci for_loops overflow primes structured_bindings

.PHONY: all clean

all: $(PROGRAMS)

constexpr_if: constexpr_if.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

fibonacci: fibonacci.cpp fibonacci_range.cpp fibonacci_iterator.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

for_loops: for_loops.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

overflow: overflow.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

primes: primes.cpp prime_range.cpp prime_iterator.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

structured_bindings: structured_bindings.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(PROGRAMS)
	