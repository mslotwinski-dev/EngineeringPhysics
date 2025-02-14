CC=gcc
CFLAGS=-Wall -pedantic -std=c11 -O2
LIBS=-lm

all: program
program: lista.o funkcje.o funkcje-wb.o
	$(CC) -o program funkcje.o lista.o $(CFLAGS) $(LIBS)
funkcje-wb.o: funkcje-wb.c
	$(CC) -o funkcje-wb.o -c funkcje-wb.c $(CFLAGS)
funkcje.o: funkcje.c lista.h
	$(CC) -o funkcje.o -c funkcje.c $(CFLAGS)
lista.o: lista.c lista.h
	$(CC) -o lista.o -c lista.c $(CFLAGS)
clean:
	rm -f *.o
