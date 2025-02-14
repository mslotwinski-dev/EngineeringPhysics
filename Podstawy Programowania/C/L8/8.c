#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct zespolona {
	float Re;
	float Im;
};

typedef struct zespolona zesp;

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

void wczytaj_zesp (zesp *z) {
	puts("Wczytaj czesc rzeczywista");
	scanf("%f", &z->Re);
	puts("Wczytaj czesc urojona");
	scanf("%f", &z->Im);
}

void wyswietl_zesp (const zesp z) { 
	printf("%f", z.Re);
	
	if (z.Im) {
		z.Im > 0 ? printf(" + ") : printf(" - ");
		printf("i%f", fabsf(z.Im));
	}	
}

zesp oblicz_zesp (zesp z1, zesp z2, int opcja) {
	zesp _z;
	switch (opcja) {
		case 1: {
			_z.Re = z1.Re + z2.Re;
			_z.Im = z1.Im + z2.Im;
			break;
		}
				
		case 2: {
			_z.Re = z1.Re - z2.Re;
			_z.Im = z1.Im - z2.Im;
			break;
		}
			
		case 3: {
			_z.Re = z1.Re*z2.Re - z1.Im*z2.Im;
			_z.Im = z1.Re*z2.Im + z1.Im*z2.Re;
			break;
		}
	}
	return _z;
}


int main(void) {
	while (true) {
		puts("Wybierz operacje");
		puts("1. Dodawanie");
		puts("2. Odejmowanie");
		puts("3. Mnozenie");
		puts("0. Zakoncz");
		
		
		int tryb = wczytaj(0, 3, "tryb menu");
		if (tryb == 0) break;
		
		zesp z1;
		zesp z2;
		puts("Wczytaj pierwsza liczbe");
		wczytaj_zesp(&z1);
		puts("Wczytaj druga liczbe");
		wczytaj_zesp(&z2);
	
		printf("(");
		wyswietl_zesp(z1);
		
		if (tryb == 1) printf(") + (");
		if (tryb == 2) printf(") - (");
		if (tryb == 3) printf(") * (");

		wyswietl_zesp(z2);
		
		printf(") = ");

		zesp _z = oblicz_zesp(z1, z2, tryb);
		
		wyswietl_zesp(_z);
		printf("\n");
		
	}
	return 0;
}
