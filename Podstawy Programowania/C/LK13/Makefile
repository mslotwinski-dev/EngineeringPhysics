# Mateusz Slotwinski
CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -O2
LIBS=-lm

all: program
program: main.o funkcje.o
	$(CC) -o program funkcje.o main.o $(CFLAGS) $(LIBS)
funkcje.o: funkcje.c main.h
	$(CC) -o funkcje.o -c funkcje.c $(CFLAGS)
lista.o: main.c main.h
	$(CC) -o main.o -c main.c $(CFLAGS)
clean:
	rm -f *.o
