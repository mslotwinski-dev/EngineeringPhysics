#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

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

void oblicz_bitowo (uint16_t a, uint16_t b, int op, uint16_t *wynik) {
	switch (op) {
		case 1: {
			*wynik = a & b;
			break;
		}
		case 2: {
			*wynik = a | b;
			break;
		}
		case 3: {
			*wynik = a ^ b;
			break;
		}
	}
}

unsigned long wizual (uint16_t x) {
	unsigned long bin = 0;
	
	for(int i = 0; i < 10; i++) {
		if((x & (1 << i))) bin += (unsigned long)pow(10, i);
	}
	
	return bin;
}


void wypisz (uint16_t a, uint16_t b, int op, uint16_t wynik) {
	printf("%d ", a);
	switch (op) {
		case 1: {
			printf("&");
			break;
		}
		case 2: {
			printf("|");
			break;
		}
		case 3: {
			printf("^");
			break;
		}
	};
	printf(" %d = %d\n", b, wynik);
}

void wypiszbin(uint16_t a, uint16_t b, int op, uint16_t wynik) {
	wypisz (wizual(a), wizual(b), op, wizual(wynik));
}

int main(void) {
	while (true) {
		puts("Wybierz operacje");
		puts("1. AND");
		puts("2. OR");
		puts("3. XOR");
		puts("0. Zakoncz");
		
		
		int tryb = wczytaj(0, 3, "tryb menu");
		if (tryb == 0) break;
		
		uint16_t x1 = wczytaj(0, UINT16_MAX >> 6, "pierwsza liczbe");
		uint16_t x2 = wczytaj(0, UINT16_MAX >> 6, "druga liczbe");
		uint16_t wynik;
		oblicz_bitowo(x1, x2, tryb, &wynik);
		wypisz(x1, x2, tryb, wynik);
		wypiszbin(x1, x2, tryb, wynik);
		
	}
	return 0;
}
