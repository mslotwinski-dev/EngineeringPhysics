CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -O2
LIBS=-lm

all: program
program: 10.o funkcje.o
	$(CC) -o program funkcje.o 10.o $(CFLAGS) $(LIBS)
funkcje.o: funkcje.c 10.h
	$(CC) -o funkcje.o -c funkcje.c $(CFLAGS)
10.o: 10.c 10.h
	$(CC) -o 10.o -c 10.c $(CFLAGS)
clean:
	rm -f *.o
