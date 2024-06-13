#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct s_data {
	int ds;
	int mm;
	int rh;
};

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

void data_czas (char * data, char * czas, char znak) {
	struct s_data o_data;
	o_data.rh = wczytaj(1970, 2024, "rok");
	o_data.mm = wczytaj(1, 12, "miesiac");
	o_data.ds = wczytaj(1, 31, "dzien");
	
	struct s_data o_czas;
	
	o_czas.rh = wczytaj(0, 23, "godzine");
	o_czas.mm = wczytaj(0, 60, "minute");
	o_czas.ds = wczytaj(0, 60, "sekunde");
	
	sprintf(czas,"%02d%c%02d%c%02d", o_czas.rh, znak, o_czas.mm, znak, o_czas.ds);
	sprintf(data,"%02d-%02d-%04d", o_data.ds, o_data.mm, o_data.rh);
}

void wypisz (const char * data, const char * czas, const char ustalony_tekst[]) {
	
	char* caly_string = (char*)calloc(sizeof(char), strlen(ustalony_tekst)+strlen(data) + strlen(czas) + 2);
	if (!caly_string) {
		fputs ("Blad alokacji pamieci!", stderr);
		exit (1);
	}
	strcpy(caly_string, ustalony_tekst);
	
	strcat(caly_string, data);
	strcat(caly_string, " ");
	strcat(caly_string, czas);
	
	puts(caly_string);
	
	free(caly_string);
}

int main() {
	while (true) {
		static char data[20];
		static char czas[20];
		
		puts("Wybierz operacje");
		puts("1. Zaplanuj date");
		puts("2. Wypisz date");
		puts("0. Zakoncz");
		
		int tryb = wczytaj(0, 2, "tryb menu");
		if (tryb == 0) break;

		switch (tryb) {
			case 1: {
				char znak;
				
				puts("Wybierz format czasu");
				puts("1. gg.mm.ss");
				puts("2. gg:mm:ss");
					
				int format = wczytaj(1, 2, "format");
				if (format == 1) znak = '.'; else  znak = ':';
				
				data_czas(data, czas, znak);
				
				break;
			}
				
			case 2: {
				wypisz(data, czas, "Wybrana data to ");
				break;
			}
		}
	}
	return 0;
}
