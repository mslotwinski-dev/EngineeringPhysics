#include "10.h"

int wczytaj(int min, int max, char * co_czytasz) {
	int tryb;
	printf("Wczytaj %s w granicach od %d do %d\n",co_czytasz, min, max);
	while (true) {
		scanf("%d", &tryb);
		
		if (tryb <= max && tryb >= min ) break;
		
		puts("Nieprawidlowa operacja");
	}
	
	return tryb;

}

int uzupelnij_dane (czesc * d) {
	static int ilosc = 0; 
	
	d->numer_katalogowy = wczytaj(10000, 50000, "numer katalogowy");
	puts("Wczytaj nazwe czesci (max 20 liter)");
	scanf("%s", d->nazwa);
	puts("Wczytaj model samochodu (zastap spacje znakiem _) (max 40 liter)");
	scanf("%s", d->model_samochodu);
	char * znak;
	while ((znak=strchr(d->model_samochodu,'_'))!=NULL) {
		*znak=' ';
	}
	
	puts("Lista kategorii");
	puts("1. Naped");
	puts("2. Zawieszenie");
	puts("3. Elektryka");
	int kat = wczytaj(1, 3, "kategorie");
	switch (kat) {
		case 1: {
			strcpy(d->kategoria, "Naped");
			break;
		}
		case 2: {
			strcpy(d->kategoria, "Zawieszenie");
			break;
		}
		case 3: {
			strcpy(d->kategoria, "Elektryka");
			break;
		}
	}
	
	puts("Typ samochodu");
	puts("1. Osobowy");
	puts("2. Dostawczy");
	int typ = wczytaj(1, 2, "typ samochodu");
		switch (typ) {
		case 1: {
			d->typ = OSOBOWY;
			puts("Wczytaj ilosc osob");
			scanf("%d", &d->pojemnosc.liczba_osob);
			break;
		}
		case 2: {
			d->typ = DOSTAWCZY;
			puts("Wczytaj ladownosc");
			scanf("%f", &d->pojemnosc.ladownosc);
			break;
		}
	}
	
	d->liczba_porzadkowa = ilosc + 1;
	
	ilosc++;
	
	return ilosc - 1;
}

void wypisz_magazyn (czesc *bib, int n) {
	printf("Magazyn\n\n");
	printf("%-3s | %-14s | %-22s | %-42s | %-15s | %-15s | %-15s \n", "n", "nr katalogowy", "nazwa", "model", "kategoria", "typ", "pojemnosc");
	for (int i = 0; i < n; i++) {
		printf("%-3d | %-14d | %-22s | %-42s | %-15s | %-15s | %-15lf \n", bib[i].liczba_porzadkowa, bib[i].numer_katalogowy, bib[i].nazwa, bib[i].model_samochodu, bib[i].kategoria, bib[i].typ ? "Osobowy" : "Dostawczy", bib[i].typ ? bib[i].pojemnosc.liczba_osob : bib[i].pojemnosc.ladownosc);
	}	
}

void magazyn (czesc * pbib, int rozmiar_max, int * pozycja) {
	uzupelnij_dane (czesc * d);
}
