# Mateusz Slotwinski
CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -O2
LIBS=-lm

all: program
program: main.o funkcje.o funkcje2.o funkcje-wb.o
	$(CC) -o program funkcje.o main.o funkcje2.o funkcje-wb.o $(CFLAGS) $(LIBS)
main.o: main.c main.h
	$(CC) -o main.o -c main.c $(CFLAGS)
funkcje.o: funkcje.c main.h
	$(CC) -o funkcje.o -c funkcje.c $(CFLAGS)
funkcje2.o: funkcje2.c main.h
	$(CC) -o funkcje2.o -c funkcje2.c $(CFLAGS)
funkcje-wb.o: funkcje-wb.c main.h
	$(CC) -o funkcje-wb.o -c funkcje-wb.c $(CFLAGS)
clean:
	rm -f *.o
