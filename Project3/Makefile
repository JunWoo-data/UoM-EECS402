all: project3.exe

main.o: main.cpp constants.h RowColumnClass.h ColorClass.h RectangleClass.h PpmImageClass.h PaternClass.h printMainMenu.h checkMenuNumber.h calculateCenterAndHalfValues.h
	g++ -std=c++98 -g -Wall -c main.cpp -o main.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -g -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h checkMenuNumber.h
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h RowColumnClass.h ColorClass.h
	g++ -std=c++98 -g -Wall -c RectangleClass.cpp -o RectangleClass.o

PpmImageClass.o: PpmImageClass.cpp PpmImageClass.h constants.h RowColumnClass.h ColorClass.h RectangleClass.h PaternClass.h
	g++ -std=c++98 -g -Wall -c PpmImageClass.cpp -o PpmImageClass.o

PaternClass.o: PaternClass.cpp PaternClass.h constants.h RowColumnClass.h ColorClass.h
	g++ -std=c++98 -g -Wall -c PaternClass.cpp -o PaternClass.o

printMainMenu.o: printMainMenu.cpp printMainMenu.h
	g++ -std=c++98 -g -Wall -c printMainMenu.cpp -o printMainMenu.o

checkMenuNumber.o: checkMenuNumber.cpp  checkMenuNumber.h
	g++ -std=c++98 -g -Wall -c checkMenuNumber.cpp -o checkMenuNumber.o

calculateCenterAndHalfValues.o: calculateCenterAndHalfValues.cpp calculateCenterAndHalfValues.h constants.h RowColumnClass.h
	g++ -std=c++98 -g -Wall -c calculateCenterAndHalfValues.cpp -o calculateCenterAndHalfValues.o

project3.exe: main.o RowColumnClass.o ColorClass.o RectangleClass.o PpmImageClass.o PaternClass.o printMainMenu.o checkMenuNumber.o calculateCenterAndHalfValues.o
	g++ main.o RowColumnClass.o ColorClass.o RectangleClass.o PpmImageClass.o PaternClass.o printMainMenu.o checkMenuNumber.o calculateCenterAndHalfValues.o -o project3.exe

clean:
	rm -f *.o *.exe
