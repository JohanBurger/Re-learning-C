CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
GTEST_LIBS = -lgtest -lgmock -lgtest_main -pthread


tests: tests.o optional.o
	$(CXX) $(CXXFLAGS) tests.o optional.o $(GTEST_LIBS) -o tests

tests.o: tests.cpp optional.h pairs.h
	$(CXX) $(CXXFLAGS) -c tests.cpp -o tests.o

optional.o: optional.cpp optional.h
	$(CXX) $(CXXFLAGS) -c optional.cpp -o optional.o

.PHONY: test
test: tests
	./tests

.PHONY: clean
clean:
	rm -f tests tests.o optional.o