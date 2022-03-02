all: project4.exe

project4.o: project4.cpp LinkedNodeClass.h SortedListClass.h FIFOQueueClass.h LIFOStackClass.h
	g++ -std=c++98 -g -Wall -c project4.cpp -o project4.o

LinkedNodeClass.o: LinkedNodeClass.cpp LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c LinkedNodeClass.cpp -o LinkedNodeClass.o

SortedListClass.o: SortedListClass.cpp SortedListClass.h LinkedNodeClass.h	
	g++ -std=c++98 -g -Wall -c SortedListClass.cpp -o SortedListClass.o

FIFOQueueClass.o: FIFOQueueClass.cpp FIFOQueueClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c FIFOQueueClass.cpp -o FIFOQueueClass.o

LIFOStackClass.o: LIFOStackClass.cpp LIFOStackClass.h LinkedNodeClass.h
	g++ -std=c++98 -g -Wall -c LIFOStackClass.cpp -o LIFOStackClass.o

project4.exe: project4.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o
	g++ project4.o LinkedNodeClass.o SortedListClass.o FIFOQueueClass.o LIFOStackClass.o -o project4.exe

clean:
	rm -f *.o *.exe