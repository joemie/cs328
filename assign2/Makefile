FLAGS= -w -Wall -s -pedantic-errors

default: all

all: driver

driver: driver.o parser.o
	g++ driver.o parser.o -o driver

driver.o: driver.cpp parser.h
	g++ -c driver.cpp -o driver.o

parser.o: parser.cpp parser.h
	g++ -c parser.cpp -o parser.o

clean:
#	-@rm core > /dev/null 2>&1
	-@rm *.o 2>&1
	-@rm driver 2>&1
