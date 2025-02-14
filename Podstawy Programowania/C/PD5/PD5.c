// Mateusz Słotwiński
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Programu nie poprawialem, na lekcji byl już gotowy


int main() {
	int n = 0;
	char plik_dane[30];
	double* tablica = NULL;

	while (true) {
		puts("Wybierz operacje");
		puts("1. Wczytaj i wyświetl dane");
		puts("2. Oblicz i wyświetl wartosc srednia");
		puts("0. Zakoncz");
		int tryb;
		scanf("%d", &tryb);

		if (tryb == 0) break;
		if (tryb > 2 || tryb < 0) {
			puts("Nieprawidlowa operacja");
			continue;
		}


		switch (tryb) {
			case 1: {

				puts("Wybierz nazwe pliku");
				scanf("%s", &plik_dane);
				FILE* plik = fopen(plik_dane, "r");
				if (!plik) {
					printf("Nie moge czytac z pliku %s\n", plik_dane);
					continue;
				}
				int lines = 0;
				fscanf(plik, "%d", &lines);

				while (true) {
					printf("Wybierz liczbe elementow od 52 do %d\n", lines);
					scanf("%d", &n);

					if (n < 52 || n > lines) {
						puts("Nieprawidlowa liczba");
						continue;
					}
					break;
				}
				
				tablica = (double*)calloc(sizeof(double), n);


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
				if (!tablica) {
					break;
				}

				for (int i = 0; i < n; i++) {
					srednia += tablica[i];
				}

				srednia /= n;

				double values = 0;
				for (int i = 0; i < n; i++) {
					values += pow(tablica[i] - srednia, 2);
				}

				double variance = values / n;
				double uA = 0;
				if (n != 0) {
					uA = sqrt(variance) / sqrt(n);
				}


				printf("Zapisac do pliku czy wyswietlic na ekranie. \nWpisz 1 jesli zapisac, aby wyswietlic nacisnij inny przycisk.\n");
				int czyzapis;

				scanf("%d", &czyzapis);

				if (czyzapis == 1) {
					FILE* plik = fopen("srednia.txt", "a");

					fprintf(plik, "%s %.4lf %d %.4lf \n", plik_dane, srednia, n, uA);
					fclose(plik);

				}
				else {
					printf("Srednia pomiarow wzrostu dla %d pomiarow wynosi %.4lf\n", n, srednia);
					printf("Odchylenie standardowe sredniej wynosi %.4lf\n", uA);
				}
				break;
			}
		}
	}
	return 0;
}