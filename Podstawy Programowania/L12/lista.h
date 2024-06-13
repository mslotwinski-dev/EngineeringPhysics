#ifndef _lista_h_
#define _lista_h_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct structlinia {
	int nr;
	char tablica[30];
	struct structlinia* next;
};


typedef struct structlinia linia;

int wczytaj(int min, int max, char * co_czytasz);

linia * tworzobiekt (FILE * plik, int znaki);

void wyswietlall (linia * plinia, int * ile);

linia * tworzliste (FILE * plik, int znaki); 

#endif
