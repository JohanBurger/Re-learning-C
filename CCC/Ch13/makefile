CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
GTEST_LIBS = -lgtest -lgmock -lgtest_main -pthread


tests: tests.o
	$(CXX) $(CXXFLAGS) tests.o  $(GTEST_LIBS) -o tests

tests.o: tests.cpp
	$(CXX) $(CXXFLAGS) -c tests.cpp -o tests.o

.PHONY: test
test: tests
	./tests

.PHONY: clean
clean:
	rm -f tests tests.o 