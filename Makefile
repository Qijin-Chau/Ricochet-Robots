# Comp 15: Data Structures
# Tufts University
# NAME: Qijin Chau
# DATE: 10/23/19
# Makefile for Ricochet Robots assignment
#

CXX      = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3


INCLUDES = $(shell echo Board.h)


gorobots: main.o Board.o Tree.o
	$(CXX) $(LDFLAGS) -o gorobots main.o Board.o Tree.o

tests: unitTests.o Board.o
	$(CXX) $(LDFLAGS) -o tests unitTests.o Board.o

main.o:  main.cpp Board.h
Board.o:  Board.cpp Board.h
Tree.o:  Tree.cpp Tree.h Board.h 
unitTests.o:  unitTests.cpp Board.h

.PHONY: clean
clean:
	rm -f ${EXECS} *.o *.dSYM./

