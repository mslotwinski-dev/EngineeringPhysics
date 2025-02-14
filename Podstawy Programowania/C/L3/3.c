//Mateusz Slotwinski

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
	puts("Witamy w kalkulatorze");
	while (true) {
		
		puts("Wybierz dzialanie matematyczne");
		puts("1. Dodawanie");
		puts("2. Odejmowanie");
		puts("3. Mnozenie");
		puts("4. Reszta z dzielenia");
		puts("0. Zakoncz");
		int tryb;
		scanf("%d", &tryb);

		if (tryb == 0) break;
		if (tryb > 4) {
			puts("Nieprawidlowa operacja");
			continue;
		}
		
		double x_1;
		puts("Wybierz pierwsza liczbe");
		scanf("%lf", &x_1);
		
		double x_2;
		puts("Wybierz druga liczbe");
		scanf("%lf", &x_2);
		
		switch (tryb) {
			case 1: 
				printf("%.2lf + %.2lf = %.2lf\n", x_1, x_2, x_1 + x_2);
				break;
			case 2: 
				printf("%.2lf - %.2lf = %.2lf\n", x_1, x_2, x_1 - x_2);
				break;
			case 3: 
				printf("%.2lf * %.2lf = %.2lf\n", x_1, x_2, x_1 * x_2);
				break;
			case 4: 
				while (true) {
					if (roundf(x_1) != x_1 || roundf(x_2) != x_2) {
						puts("Nieprawidlowe dane - oba argumenty musza byc calkowite");
					}
					
					if (roundf(x_1) != x_1) {
						puts("Wybierz pierwsza liczbe");
						scanf("%lf", &x_1);
					}
					
					if (roundf(x_2) != x_2) {
						puts("Wybierz druga liczbe");
						scanf("%lf", &x_2);
					}
					
					if (roundf(x_1) == x_1 && roundf(x_2) == x_2) {
						printf("%d %% %d = %d \n", (int)x_1, (int)x_2, (int)x_1 % (int)x_2);
						break;
					};
				}
				
				break;
		}
	}
	return 0;
}
