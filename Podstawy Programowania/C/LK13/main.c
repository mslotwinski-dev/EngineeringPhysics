//MATEUSZ SLOTWINSKI

#include "main.h"

int main(int argc, char *arg[]) {
	if (argc != 3) {
		fputs ("Niewlasciwa liczba parametrow!\n", stderr);
		fputs ("Uzycie: wypisz (Nazwa pliku wejsciowego) (Nazwa pliku wyjsciowego)\n", stderr);
	}

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
	
	return 0;
}
