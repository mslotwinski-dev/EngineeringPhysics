// Mateusz Slotwinski
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main() {
	char sms[175];
	
	while (true) {
		puts("Wybierz operacje");
		puts("1. Wczytaj sms i wypisz go");
		puts("2. Szyfruj sms i wypisz go");
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
				puts("Wpisz tresc sms znak po znaku");
				int i = 0;
				
				while (true) {
					char c;
					scanf("%c", &c);
					if ((int)c == 27) {
						sms[i] = '\0';
						break;
					} else {
						sms[i] = c;
						i++;
					}
				}
				
				puts("Jawna tresc sms");
				puts(sms);
				
				puts("Kod sms w postaci znakow ASCII");
				for (int i = 0; i <= strlen(sms); i++) {
					printf("%d",sms[i]);
				}
				printf("\n");
				
				
				break;
			}
				
			case 2: {
				int v;
				char* szyfr = (char*)calloc(sizeof(char), strlen(sms) + 1);
				strcpy (szyfr, sms);
				puts("Wybierz wartosc przesuniecia");
				scanf("%d", &v);
				
				for (int i = 0; i <= strlen(sms); i++) {
					// WIELKIE
					if (szyfr[i] >= 65 && szyfr[i]<= 90) {
						if (szyfr[i] > 90 - v) szyfr[i] -= 26;
						szyfr[i] += v;
					}
					
					// MALE
					if (szyfr[i] >= 97 && szyfr[i]<= 122) {
						if (szyfr[i] > 122 - v) szyfr[i] -= 26;
						szyfr[i] += v;
					}
					
					// CYFRY
					if (szyfr[i] >= 48 && szyfr[i]<= 57) {
						if (szyfr[i] >= 57 - v) szyfr[i] -= 10;
						szyfr[i] += v;
					}
					
				}
				
				puts("Zaszyfrowana wiadomosc to");
				puts(szyfr);
				
				break;
			}
		}
	}
	return 0;
}
