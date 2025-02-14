#ifndef _10_h_
#define _10_h_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


enum przeznaczenie {OSOBOWY = 0, DOSTAWCZY = 1};

union wlasnosc {
    int liczba_osob;
    float ladownosc;
};

struct CzescSamochodowa {
	int liczba_porzadkowa;
	int numer_katalogowy;
	char nazwa[20];
	char model_samochodu[40];
	char kategoria[15];
	enum przeznaczenie typ;
	union wlasnosc pojemnosc;
};

typedef struct CzescSamochodowa czesc;

int wczytaj(int min, int max, char * co_czytasz);

int uzupelnij_dane (czesc * d);

void wypisz_magazyn (czesc *bib, int n);

void magazyn (czesc * pbib, int rozmiar_max, int * pozycja);

#endif
