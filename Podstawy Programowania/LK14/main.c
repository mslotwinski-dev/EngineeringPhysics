//MATEUSZ SLOTWINSKI

#include "main.h"

int main(int argc, char *arg[]) {
	
	while (true) {
		puts("Wybierz operacje");
		puts("1. Otworz plik i wczytaj dane");
		puts("2. Generuj plik i zapisz zmiany");
		puts("0. Zakoncz");
		
		
		int tryb = wczytaj(0, 3, "tryb menu");
		if (tryb == 0) break;
		
		switch (tryb) {
			case 1: {

	
				FILE *plik = fopen(arg[1], "r");
				if (!plik) {
					printf("Błąd otwarcia pliku wejściowego");
					plik = otworzplik(CZYTAJ);
				}
				naglowekg naglowek;
				czytaj_head(plik, &naglowek);
				uint8_t *dane = tablica(&naglowek);
				zapiszdane(plik, &naglowek, dane);
				fclose(plik);
				
				break;
			}

			case 2: {
				FILE *plik = fopen(arg[2], "w");
				
				if (!plik) {
					printf("Błąd otwarcia pliku wejściowego");
					plik = otworzplik(ZAPISZ);
				}
				
				naglowekg naglowek;
				tworz_head(&naglowek);
				
				uint8_t *dane = gen_rgb(&naglowek);
				zapiszdanegen(plik, &naglowek, dane);
				
				fclose(plik);
				break;
			}
		}
	}
	
	return 0;
}
