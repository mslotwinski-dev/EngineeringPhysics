#include "lista.h"

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

linia * tworzobiekt (FILE * plik, int znaki) {
	static int nr_linii = 1;
	linia *nowa = (linia*) malloc (sizeof (linia) * 16);
	if (!nowa) {
		fputs ("Blad alokacji pamieci!", stderr);
		exit (1);
	}
	
	nowa->nr = nr_linii++;
	fgets(nowa->tablica, znaki, plik);
	
	return nowa;
}

void wyswietlall (linia * plinia, int * ile) {
	linia* biezacy = NULL;
	while (biezacy)	{
		(*ile)++;
		printf ("%s\n", biezacy->tablica);
		biezacy = biezacy->next;
	}
}

linia * tworzliste (FILE * plik, int znaki) {
	linia* pierwszy; 
	linia* biezacy = NULL;
	
	while(! feof(plik)) {
		linia *nowy = tworzobiekt(plik, znaki);
		if (biezacy) biezacy->next = nowy;
		else pierwszy = nowy;
		biezacy = nowy;
	}
	
	biezacy->next = NULL;
	
	return pierwszy;
}
