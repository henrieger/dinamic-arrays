CC = gcc
CFLAGS = -Wall
# LDLIBS = 

objects = *.o

all: test

test: test.c # dinamic.o
# dinamic.o: dinamic.c dinamic.h

debug: CFLAGS += -g -DDEBUG
debug: all

clean:
	rm -rf $(objects)

purge: clean
	rm -rf test