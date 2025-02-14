// Mateusz Slotwinski
#include "9.h"

static int ilosc = 0; 

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
	
	
	d->liczba_porzadkowa = ilosc + 1;
	
	ilosc++;
	
	return ilosc - 1;
}

void wypisz_magazyn (czesc *bib, int n) {
	printf("Magazyn\n\n");
	printf("%-3s | %-14s | %-22s | %-42s | %-15s\n", "n", "nr katalogowy", "nazwa", "model", "kategoria");
	for (int i = 0; i < n; i++) {
		printf("%-3d | %-14d | %-22s | %-42s | %-15s\n", bib[i].liczba_porzadkowa, bib[i].numer_katalogowy, bib[i].nazwa, bib[i].model_samochodu, bib[i].kategoria);
	}
	
}

int main(void) {
	
	czesc *bazadanych = (czesc*) malloc (sizeof (czesc) * 16);
	if (!bazadanych) {
		fputs ("Blad alokacji pamieci!", stderr);
		exit (1);
	}
	
	while (true) {
		puts("Wybierz operacje");
		puts("1. Dopisz pozycję do bazy");
		puts("2. Wypisz bazę danych");
		puts("0. Zakoncz");
		
		int tryb = wczytaj(0, 2, "tryb menu");
		if (tryb == 0) break;

		switch (tryb) {
			case 1: {
				czesc nowaczesc;
				int n = uzupelnij_dane(&nowaczesc);
				bazadanych[n] = nowaczesc;
				break;
			}
			case 2: {
				wypisz_magazyn(bazadanych, ilosc);
				break;
			}
		}
	}
	
	free (bazadanych);
	return 0;
}
