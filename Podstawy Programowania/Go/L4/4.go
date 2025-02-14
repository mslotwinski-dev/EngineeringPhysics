package main

import (
	"fmt"
	"os"
)

func main() {
	tablica := [200]float64{0}
	n := 0
	plik_dane := "wzrost.txt"

	for true {

		fmt.Println("Wybierz dzialanie matematyczne")
		fmt.Println("1. Wczytaj i wyświetl dane")
		fmt.Println("2. Oblicz i wyświetl wartość średnią")
		fmt.Println("0. Zakoncz")
		var tryb int
		fmt.Scan(&tryb)

		if tryb == 0 {
			break
		}
		if tryb > 2 || tryb < 0 {
			fmt.Println("Nieprawidlowa operacja")
			continue
		}

		switch tryb {
		case 1:
			{
			elements:
				fmt.Println("Wybierz liczbe elementow od 52 do 200")
				fmt.Scan(&n)

				if n < 52 || n > 200 {
					fmt.Println("Nieprawidlowa liczba")
					goto elements
				}

				plik, err := os.Open(plik_dane)
				if err != nil {
					panic(err)
				}

				defer plik.Close()

				for i := 0; i < n; i++ {
					fmt.Fscanf(plik, "%f", &tablica[i])
				}

				for i := 0; i < n; i++ {
					fmt.Printf("%.4f ", tablica[i])
					if (i+1)%4 == 0 {
						fmt.Printf("\n")
					}
				}

				break
			}

		case 2:
			{
				srednia := 0.0

				for i := 0; i < n; i++ {
					srednia += tablica[i]
				}

				srednia /= float64(n)

				fmt.Printf("Zapisac do pliku czy wyswietlic na ekranie. \nWpisz 1 jesli zapisac, aby wyswietlic nacisnij inny przycisk.\n")
				var czyzapis int
				fmt.Scan(&czyzapis)

				if czyzapis == 1 {
					plik, err := os.Create("srednia.txt")
					if err != nil {
						panic(err)
					}
					fmt.Fprintf(plik, "%s %f %d \n", plik_dane, srednia, n)

				} else {
					fmt.Printf("Srednia pomiarow wzrostu dla %d pomiarow wynosi %f\n", n, srednia)
				}
				break
			}
		}
	}
}
