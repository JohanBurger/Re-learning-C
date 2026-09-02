CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
GTEST_LIBS = -lgtest -lgmock -lgtest_main -pthread

brake: brake.o mock_service_bus.o auto_brake.o
	$(CXX) $(CXXFLAGS) brake.o mock_service_bus.o auto_brake.o -o brake

brake.o: brake.cpp auto_brake.h mock_service_bus.h
	$(CXX) $(CXXFLAGS) -c brake.cpp -o brake.o

auto_brake.o: auto_brake.cpp service_bus.h
	$(CXX) $(CXXFLAGS) -c auto_brake.cpp -o auto_brake.o

# Unit tests
auto_brake_test: auto_brake_test.o auto_brake.o
	$(CXX) $(CXXFLAGS) auto_brake_test.o auto_brake.o $(GTEST_LIBS) -o auto_brake_test

auto_brake_test.o: auto_brake_test.cpp auto_brake.h 
	$(CXX) $(CXXFLAGS) -c auto_brake_test.cpp -o auto_brake_test.o

.PHONY: test
test: auto_brake_test
	./auto_brake_test

.PHONY: clean
clean:
	rm -f brake brake.o mock_service_bus.o auto_brake.o auto_brake_test auto_brake_test.o