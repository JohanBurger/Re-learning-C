CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

brake: brake.o mock_service_bus.o auto_brake.o
	$(CXX) $(CXXFLAGS) brake.o mock_service_bus.o auto_brake.o -o brake

brake.o: brake.cpp auto_brake.h mock_service_bus.h
	$(CXX) $(CXXFLAGS) -c brake.cpp -o brake.o

mock_service_bus.o: mock_service_bus.cpp mock_service_bus.h service_bus.h
	$(CXX) $(CXXFLAGS) -c mock_service_bus.cpp -o mock_service_bus.o

auto_brake.o: auto_brake.cpp service_bus.h
	$(CXX) $(CXXFLAGS) -c auto_brake.cpp -o auto_brake.o

clean:
	rm -f brake brake.o mock_service_bus.o auto_brake.o
