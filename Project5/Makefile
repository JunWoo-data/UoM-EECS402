all: project5.exe

project5.o: project5.cpp constants.h SortedListClass.h FIFOQueueClass.h EventClass.h IntersectionSimulationClass.h CarClass.h
	g++ -std=c++98 -g -Wall -c project5.cpp -o project5.o

random.o: random.cpp random.h
	g++ -std=c++98 -g -Wall -c random.cpp -o random.o

EventClass.o: EventClass.cpp EventClass.h
	g++ -std=c++98 -g -Wall -c EventClass.cpp -o EventClass.o

CarClass.o: CarClass.cpp CarClass.h
	g++ -std=c++98 -g -Wall -c CarClass.cpp -o CarClass.o

IntersectionSimulationClass.o: IntersectionSimulationClass.cpp IntersectionSimulationClass.h SortedListClass.h EventClass.h FIFOQueueClass.h CarClass.h
	g++ -std=c++98 -g -Wall -c IntersectionSimulationClass.cpp -o IntersectionSimulationClass.o

project5.exe: project5.o random.o EventClass.o CarClass.o IntersectionSimulationClass.o
	g++ project5.o random.o EventClass.o CarClass.o IntersectionSimulationClass.o -o project5.exe

clean:
	rm -f *.o *.exe