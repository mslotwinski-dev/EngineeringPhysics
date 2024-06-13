#include "lista.h"

int main(void) {
	FILE* plik = fopen("dane.txt", "r");
	if (!plik) {
		printf("Nie moge czytac z pliku %s\n", "quovadis.txt");
		exit(1);
	}
	
	int znaki;
	fscanf(plik, "%d", &znaki);
	
	linia *sterta = NULL;
	
	int ile;

				
	while (true) {
		puts("Wybierz operacje");
		puts("1. Wczytaj wzor z pliku");
		puts("2. Wypisz wzor");
		puts("3. Modyfikuj losowa linie");
		puts("0. Zakoncz");
		
		
		int tryb = wczytaj(0, 3, "tryb menu");
		if (tryb == 0) break;
		
		switch (tryb) {
			case 1: {
				sterta = tworzliste(plik, znaki);
				
				break;
			}

			case 2: {
				
				wyswietlall(sterta, &ile);
				
				break;
			}
		}
	}
	
	free(sterta);
	
	return 0;
}
