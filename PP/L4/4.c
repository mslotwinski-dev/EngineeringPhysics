#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
	double tablica[200] = {0};
	int n = 0;
	char plik_dane[] = "wzrost.txt";
	
	while (true) {
		
		puts("Wybierz dzialanie matematyczne");
		puts("1. Wczytaj i wyświetl dane");
		puts("2. Oblicz i wyświetl wartość średnią");
		puts("0. Zakoncz");
		int tryb;
		scanf("%d", &tryb);
		
		if (tryb == 0) break;
		if (tryb > 2 || tryb <0) {
			puts("Nieprawidlowa operacja");
			continue;
		}
		

		switch (tryb) {
			case 1: {
				
		
				while (true) {
					puts("Wybierz liczbe elementow od 52 do 200");
					scanf("%d", &n);
				
					if (n < 52 || n > 200) {
						puts("Nieprawidlowa liczba");
						continue;
					}
					
					break;
				}
		
				FILE *plik = fopen (plik_dane, "r");
				if (!plik) {
					puts ("Nie moge czytac z pliku wyniki.txt");
					return 1;
				}
				
				for (int i = 0; i < n; i++) {
					fscanf(plik, "%lf", &tablica[i]);
				}
				
				for (int i = 0; i < n; i++) {
					printf("%.4lf ", tablica[i]);
					if ((i + 1) % 4 == 0) printf("\n");
				}
				
				fclose(plik);
				break;
			}
				
			case 2: {
				double srednia = 0;
				
				for (int i = 0; i < n; i++) {
					srednia += tablica[i];
				}
				
				srednia /= n;
				
				
				printf("Zapisac do pliku czy wyswietlic na ekranie. \nWpisz 1 jesli zapisac, aby wyswietlic nacisnij inny przycisk.\n");
				int czyzapis;
				
				scanf("%d", &czyzapis);
				
				if (czyzapis == 1) {
					FILE *plik = fopen ("srednia.txt", "a");
					
					fprintf(plik, "%s %lf %d \n", plik_dane, srednia, n);
					fclose(plik);
				
				} else {
					printf("Srednia pomiarow wzrostu dla %d pomiarow wynosi %lf\n", n, srednia);
				}
				break;
			}
		}
	}
	return 0;
}
