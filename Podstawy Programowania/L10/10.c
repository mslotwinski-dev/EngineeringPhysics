// Mateusz Slotwinski
#include "10.h"

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
		
		static int n = 0;

		switch (tryb) {
			case 1: {
				if (n == 15) {
					puts("Magazyn pelny");
					break;
				}
	
				czesc nowaczesc;
				n = uzupelnij_dane(&nowaczesc);
				bazadanych[n] = nowaczesc;
				break;
			}
			case 2: {
				wypisz_magazyn(bazadanych, n);
				break;
			}
		}
	}
	
	free (bazadanych);
	return 0;
}
