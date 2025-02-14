// Mateusz Slotwinski
#include <stdio.h>

int main(void) {
	char p1[32];
	int g1;
	
	puts("Podaj pierwszy przedmiot");
	scanf("%s", p1);
	printf("Podaj liczbe godzin dla przedmiotu %s\n", p1);
	scanf("%d", &g1);

	
	char p2[32];
	int g2;
	puts("Podaj drugi przedmiot");
	scanf("%s", p2);
	printf("Podaj liczbe godzin dla przedmiotu %s\n", p2);
	scanf("%d", &g2);

	
	char p3[32];
	int g3;
	puts("Podaj trzeci przedmiot");
	scanf("%s", p3);
	printf("Podaj liczbe godzin dla przedmiotu %s\n", p3);
	scanf("%d", &g3);
	
	double u1, u2, u3;
	int sum = g1 + g2 + g3;
	u1 = 100.0*g1 / sum;
	u2 = 100.0*g2 / sum;
	u3 = 100.0*g3 / sum;
	
	printf("Lista przedmiotow\n\n");
	printf("%-25s | %-12s | %-10s\n", "Przedmiot", "Liczba godzin", "Udzial");
	printf("%-25s | %-12dh | %-10.2lf %% \n", p1, g1, u1);
	printf("%-25s | %-12dh | %-10.2lf %% \n", p2, g2, u2);
	printf("%-25s | %-12dh | %-10.2lf %% \n", p3, g3, u3);
	
	char nplik[32];
	puts("Podaj nazwe pliku");
	scanf("%s", nplik);
	
	FILE *plik = fopen (nplik, "a");
	if (!plik) {
		puts ("Nie moge czytac z pliku wyniki.txt");
		return 1;
	}
	
	fprintf(plik, "Lista przedmiotow\n\n");
	fprintf(plik, "%-25s | %-12s | %-10s\n", "Przedmiot", "Liczba godzin", "Udzial");
	fprintf(plik, "%-25s | %-12dh | %-10.2lf %% \n", p1, g1, u1);
	fprintf(plik, "%-25s | %-12dh | %-10.2lf %% \n", p2, g2, u2);
	fprintf(plik, "%-25s | %-12dh | %-10.2lf %% \n", p3, g3, u3);
	fprintf(plik, "\n\n");
	
	fclose (plik);
	return 0;
}
