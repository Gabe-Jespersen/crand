CC = g++
CFLAGS = -O2 -g -std=c++11 -fpermissive -Wall

all: crand

crand: main.o parse.o
	$(CC) $(CFLAGS) main.o parse.o -o crand

main.o: main.cpp parse.h
	$(CC) $(CFLAGS) -c main.cpp

parse.o: parse.cpp parse.h
	$(CC) $(CFLAGS) -c parse.cpp


clean:
	rm -rf *.o crand

install:
	make
	cp crand /usr/bin/crand

uninstall:
	rm /usr/bin/crand
