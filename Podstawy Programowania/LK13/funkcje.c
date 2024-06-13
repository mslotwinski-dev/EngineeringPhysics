//MATEUSZ SLOTWINSKI

#include "main.h"

FILE *otworzplik (rodzaj_pracy tryb) {
	FILE * plik = NULL;
	while(plik == NULL) {
		if (tryb == CZYTAJ) printf("Podaj nazwe pliku do odczytu: \n");
		else printf("Podaj nazwe pliku do zapisu !\n");
		char nazwa[30];
		scanf("%s",nazwa);
		plik = fopen(nazwa, tryb == CZYTAJ ? "r" : "w");
		if (!plik) { 
			printf("Błąd otwarcia pliku \n"); 
		}
	}
	return plik;	
}

void czytaj_head (const FILE * plik1, naglowekg * header) {
	uint16_t typtmp;

	fscanf((FILE *)plik1, "%hu", &typtmp);
	fscanf((FILE *)plik1, "%hu", &header->w);
	fscanf((FILE *)plik1, "%hu", &header->h);
	fscanf((FILE *)plik1, "%hhu", &header->kolor);
	fscanf((FILE *)plik1, "%hhu", &header->kompresja);
	getc((FILE *)plik1);

	header->typa = (char) typtmp;
	header->typb = (char)(typtmp >> 8);
}

uint8_t * tablica (const naglowekg * header) {
	if (header->w == 0 || header->h == 0) {
    printf("Blad: szerokosc lub wysokosc jest rowna 0\n");
    exit(1);
  }

	uint8_t *dane = (uint8_t *) calloc (sizeof(uint8_t), (header->w)*(header->h)* (header->kolor ? 3 : 1));
	if (!dane) {
		fputs ("Blad alokacji pamieci!", stderr);
		exit (1);
	}
	
	return dane;
}

void czytaj_dane (const FILE * plik1, const naglowekg * header, uint8_t * dane) {
	for(int j = 0; j < header->h; j++) {
		for(int i = 0; i < header->w * (header->kolor ? 3 : 1); i++) {
			fscanf((FILE *) plik1, "%hhu ", &dane[j * header->w * (header->kolor ? 3 : 1) +i ]);
		}
	}
}

void zapiszdane (FILE * stream, const naglowekg * header, const uint8_t * dane) {

	fprintf(stream,"Typ pliku = %c%c\n",header->typa,header->typb);
	fprintf(stream,"Szerokosc grafiki = %hu\n",header->w);
	fprintf(stream,"Wysokosc grafiki = %hu\n",header->h);
	fprintf(stream,"Kolor grafiki = %hhu\n",header->kolor);
	fprintf(stream,"Kompresja grafiki = %hhu\n",header->kompresja);
	for(int j = 0; j < header->w; j++) {
		for(int i = 0; i < header->h*(header->kolor ? 3 : 1); i++) {
			fprintf(stream, "%hhu ", dane[j * header->w * (header->kolor ? 3 : 1)+i]);
		}
		fprintf(stream,"\n");
	}
}
