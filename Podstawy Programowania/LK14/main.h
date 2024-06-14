//MATEUSZ SLOTWINSKI

#ifndef _main_h_
#define _main_h_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

struct _naglowekg {
	char typa;
	char typb;
	uint16_t w;
	uint16_t h;
	uint8_t kolor;
	uint8_t kompresja;
};

typedef struct _naglowekg naglowekg;

typedef enum {
	CZYTAJ,
	ZAPISZ,
}  rodzaj_pracy;

int16_t losuj_int (int16_t pocz, int16_t koniec);

int wczytaj(int min, int max, char * co_czytasz);

FILE *otworzplik (rodzaj_pracy tryb);

void czytaj_head (const FILE * plik1, naglowekg * header);

uint8_t * tablica (const naglowekg * header);

void czytaj_dane (const FILE * plik1, const naglowekg * header, uint8_t * dane);

void zapiszdane (FILE * stream, const naglowekg * header, const uint8_t * dane);

void tworz_head (naglowekg * header2);

uint8_t *gen_rgb(naglowekg * header2);

void zapiszdanegen (FILE * stream, const naglowekg * header, const uint8_t * dane);

#endif
