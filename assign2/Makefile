FLAGS= -w -Wall -s -pedantic-errors

default: all

all: driver

driver: driver.o parser.o indexOutOfRangeError.o
	g++ driver.o parser.o indexOutOfRangeError.o -o driver

driver.o: driver.cpp parser.h quat.h quat.hpp indexOutOfRangeError.h
	g++ -c driver.cpp -o driver.o

parser.o: parser.cpp parser.h quat.h
	g++ -c parser.cpp -o parser.o

indexOutOfRangeError.o: indexOutOfRangeError.cpp indexOutOfRangeError.h
	g++ -c indexOutOfRangeError.cpp -o indexOutOfRangeError.o

clean:
#	-@rm core > /dev/null 2>&1
	-@rm *.o 2>&1
	-@rm driver 2>&1
