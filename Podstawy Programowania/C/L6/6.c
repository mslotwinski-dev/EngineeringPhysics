// Mateusz Slotwinski
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	while (true) {
		puts("Wybierz z menu");
		puts("1. Wczytaj tekst do analizy");
		puts("2. Wypisz tekst i szukaj wzorca");
		puts("0. Zakoncz");
		int tryb;
		scanf("%d", &tryb);
		
		static char* tablica;
		
		if (tryb == 0) {
			free(tablica);
			break;
		}
		if (tryb > 2 || tryb <0) {
			puts("Nieprawidlowa operacja");
			continue;
		}
		
		
		switch (tryb) {
			case 1: {
				int n;
				printf("Wybierz dlugosc tekstu\n");
				scanf("%d", &n);
				
				tablica = (char*)calloc(sizeof(char), n+1);
				if (!tablica) {
					fputs ("Blad alokacji pamieci!", stderr);
					exit (1);
				}
				
				FILE* plik = fopen("quovadis.txt", "r");
				if (!plik) {
					printf("Nie moge czytac z pliku %s\n", "quovadis.txt");
					continue;
				}
				
				int i_0;
				
				while (true) {
					printf("Wybierz indeks poczatkowego znaku (min 400)\n");
					scanf("%d", &i_0);
					if (i_0 < 400) {
						puts("Nieprawidlowe dane, sprobuj z liczba wieksza od 400");
						continue;
					}
					break;
				}
				
				for (int i = 0; i < n+i_0; i++) {
					char c = fgetc(plik);
					if (i >= i_0) {
						*(tablica + i) = c;
					}
				}
				
				fclose(plik);
				
				break;
			}

			case 2: {
				puts(tablica);
								
				char slowo[30];
				printf("Wybierz slowo do wyszukania\n");
				scanf("%s", slowo);
				
				char* wsk = strstr(tablica, slowo);
				printf ("Znalazlem slowo %s na pozycji %zu\n", slowo, wsk - tablica + 1);
				
				break;
			}
		}
	}
	
	return 0;
}
