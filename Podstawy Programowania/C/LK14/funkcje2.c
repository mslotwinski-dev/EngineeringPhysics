//MATEUSZ SLOTWINSKI

#include "main.h"

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

void tworz_head (naglowekg * header2) {
	printf("Wpisz typ pliku (dwa znaki): ");
	char typtmp[2];
	scanf("%s", typtmp);
	header2->typa = typtmp[0];
	header2->typb = typtmp[1];
	
	printf("Wpisz szerokosc pliku (wieksze od zera): ");
	scanf("%hu", &header2->w);
	
	printf("Wpisz wysokosc pliku (wieksze od zera): ");
	scanf("%hu", &header2->h);
	
	int tmpcolor = 0;
	printf("Czy obraz powinien byc w kolorze? Jesli tak napisz 1: ");
	scanf("%d", &tmpcolor);
	if (tmpcolor == 1) header2->kolor = 1;
	else header2->kolor = 0;
	
	int tmpcomp = 0;
	printf("Czy uzyc kompresji? Jesli tak napisz 1: ");
	scanf("%d", &tmpcomp);
	if (tmpcomp == 1) header2->kompresja = 1;
	else header2->kompresja = 0;
}

uint8_t *gen_rgb(naglowekg * header2) {
	uint8_t *dane = tablica(header2);

	
	for(int j = 0; j < header2->h; j++) {
		for(int i = 0; i < header2->w * (header2->kolor ? 3 : 1); i++) {
			dane[j * header2->w * (header2->kolor ? 3 : 1) +i ] = losuj_int(0, 255);
		}
	}
	
	return dane;
	
}

void zapiszdanegen (FILE * stream, const naglowekg * header, const uint8_t * dane) {
	// NIE ZDAZYLEM JUZ ODKODOWAC ;C
	fprintf(stream,"%c%c ",header->typa, header->typb);
	fprintf(stream,"%hu ",header->w);
	fprintf(stream,"%hu ",header->h);
	fprintf(stream,"%hhu ",header->kolor);
	fprintf(stream,"%hhu ",header->kompresja);
	
	for(int j = 0; j < header->w; j++) {
		for(int i = 0; i < header->h*(header->kolor ? 3 : 1); i++) {
			fprintf(stream, "%hhu ", dane[j * header->w * (header->kolor ? 3 : 1)+i]);
		}
	}
}
