CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
GTEST_LIBS = -lgtest -lgmock -lgtest_main -pthread

smart_pointers: smart_pointers.o
	$(CXX) $(CXXFLAGS) smart_pointers.o $(GTEST_LIBS) -o smart_pointers

smart_pointers.o: smart_pointers.cpp
	$(CXX) $(CXXFLAGS) -c smart_pointers.cpp -o smart_pointers.o

.PHONY: test
test: smart_pointers
	./smart_pointers

.PHONY: clean
clean:
	rm -f smart_pointers smart_pointers.o
