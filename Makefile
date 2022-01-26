CC = gcc
CFLAGS = -Wall
# LDLIBS = 

objects = *.o

all: test

test: test.c # dynamic.o
# dynamic.o: dynamic.c dynamic.h

debug: CFLAGS += -g -DDEBUG
debug: all

clean:
	rm -rf $(objects)

purge: clean
	rm -rf test