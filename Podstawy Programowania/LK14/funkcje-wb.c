//Co. 2015-2024 Waldemar Bajdecki
// plik do dyspozycji studentow, pod warunkiem uzycia w projekcie w niezmienionej formie
// plik powinien byc kompilowany w osobnej linii w Makefile i dolaczony do projektu finalnego
// naglowki funkcji powinny byc umieszczone we wlasnym pliku naglowkowym

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//funkcja wczytujaca int32_t w okreslonych granicach i informujaca co jest wczytywane i w jakich granicach
//jest alternatywna do funkcji zdefiniowanej przez studenta, pozwala czytac dane w szerszym zakresie wartosci
// dla typow char, int, int8_t, uint8_t, int16_t, uint16_t, int32_t 
// oraz w ograniczonym zakresie dla unsigned, uint32_t gdy gorna granica nie wieksza niz INT32_MAX=(UINT32_MAX-1)/2
// przy uzyciu wynik powinien byc zrzutowany na wlasciwy typ
int32_t wczytaj_int32 (int32_t d_gran, int32_t g_gran, const char * komunikat)
{
	int32_t wybor=0;
	printf("Podaj %s z zakresu <%d, %d>: ",komunikat, d_gran, g_gran);
	do
	{
		scanf("%d",&wybor);	
	}
	while(wybor<d_gran || wybor >g_gran);
	return wybor; 
}

//funkcja zwracajaca wartosc losowa int z podanego zakresu
// dla typow char, int8_t, uint8_t, int16_t 
// oraz w ograniczonym zakresie dla uint16_t gdy gorna granica nie wieksza niz INT16_MAX=(UINT16_MAX-1)/2
// przy uzyciu wynik powinien byc zrzutowany na wlasciwy typ
int16_t losuj_int (int16_t pocz, int16_t koniec)
{
	int16_t t=rand()%(koniec-pocz+1)+pocz;
	return t;
}
