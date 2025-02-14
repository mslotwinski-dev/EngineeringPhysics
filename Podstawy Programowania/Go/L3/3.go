package main

import "fmt"

func main() {
	fmt.Println("Witamy w kalkulatorze")
	for true {

		fmt.Println("Wybierz dzialanie matematyczne")
		fmt.Println("1. Dodawanie")
		fmt.Println("2. Odejmowanie")
		fmt.Println("3. Mnozenie")
		fmt.Println("4. Reszta z dzielenia")
		fmt.Println("0. Zakoncz")

		var tryb int
		fmt.Scan(&tryb)

		if tryb == 0 {
			break
		}
		if tryb > 4 {
			fmt.Println("Nieprawidlowa operacja")
			continue
		}

		var x_1 float64
		fmt.Println("Wybierz pierwsza liczbe")
		fmt.Scan(&x_1)

		var x_2 float64
		fmt.Println("Wybierz druga liczbe")
		fmt.Scan(&x_2)

		switch tryb {
		case 1:
			fmt.Printf("%.2f + %.2f = %.2f\n", x_1, x_2, x_1+x_2)
		case 2:
			fmt.Printf("%.2f - %.2f = %.2f\n", x_1, x_2, x_1-x_2)
		case 3:
			fmt.Printf("%.2f * %.2f = %.2f\n", x_1, x_2, x_1*x_2)
		case 4:
			for true {
				if float64(int(x_1)) != x_1 || float64(int(x_2)) != x_2 {
					fmt.Printf("Nieprawidlowe dane - oba argumenty musza byc calkowite")
				}

				if float64(int(x_1)) != x_1 {
					fmt.Printf("Wybierz pierwsza liczbe")
					fmt.Scan("%lf", &x_1)
				}

				if float64(int(x_2)) != x_2 {
					fmt.Printf("Wybierz druga liczbe")
					fmt.Scan("%lf", &x_2)
				}

				if float64(int(x_1)) == x_1 && float64(int(x_2)) == x_2 {
					fmt.Printf("%d %% %d = %d \n", int(x_1), int(x_2), int(x_1)%int(x_2))
					break
				}
			}
		}

	}
}
