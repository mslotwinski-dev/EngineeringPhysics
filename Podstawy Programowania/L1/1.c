// Mateusz Slotwinski

#include <stdio.h>

int main(void) {
	double a,b;
	puts("Podaj a i b");
	scanf("%lf%lf", &a, &b);
	
	if (a != 0) {
		printf("%.3f\n",-b/a);
	} else if (b != 0) {
		puts("Brak");
	} else {
		puts("Jest ich nieskonczenie wiele");
	}
	
	return 0;
}
