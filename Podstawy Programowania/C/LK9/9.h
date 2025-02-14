#ifndef _9_h_
#define _9_h_ "9.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct CzescSamochodowa {
	int liczba_porzadkowa;
	int numer_katalogowy;
	char nazwa[20];
	char model_samochodu[40];
	char kategoria[15];
};

typedef struct CzescSamochodowa czesc;

int wczytaj(int min, int max, char * co_czytasz);

int uzupelnij_dane (czesc * d);

void wypisz_magazyn (czesc *bib, int n);

#endif
