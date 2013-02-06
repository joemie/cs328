#Joseph Kurtz
#CS328 Assignment 1
#Feb 4, 2013
#An example makefile

FLAGS= -w -Wall -s -pedantic-errors

default: all

all: driver


driver: signal.o parser.o tokenlist.o token.o scanner.o 
	g++ signal.o parser.o tokenlist.o token.o scanner.o -o driver

Amatrix.o: Avector.h Avector.h signal.h


parser.o: parser.cpp parser.h tokenlist.h token.h enTokens.h Amatrix.h Avector.h signal.h
	g++ -c parser.cpp -o parser.o

scanner.o: scanner.cpp scanner.h enChar.h tokenlist.h token.h enTokens.h signal.h
	g++ -c scanner.cpp -o scanner.o

signal.o: signal.cpp signal.h
	g++ -c signal.cpp -o signal.o

token.o: token.cpp token.h enTokens.h
	g++ -c token.cpp -o token.o

tokenlist.o: tokenlist.cpp tokenlist.h token.h enTokens.h signal.h
	g++ -c tokenlist.cpp -o tokenlist.o

clean:
	-@rm core > /dev/null 2>&1
	-@rm *.o 2>&1
	-@rm driver 2>&1
