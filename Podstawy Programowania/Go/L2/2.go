package main

import (
	"fmt"
	"os"
)

func main() {
	var p1 string
	var g1 float64

	fmt.Println("Podaj pierwszy przedmiot")
	fmt.Scan(&p1)
	fmt.Printf("Podaj liczbe godzin dla przedmiotu %s\n", p1)
	fmt.Scan(&g1)

	var p2 string
	var g2 float64

	fmt.Println("Podaj drugi przedmiot")
	fmt.Scan(&p2)
	fmt.Printf("Podaj liczbe godzin dla przedmiotu %s\n", p2)
	fmt.Scan(&g2)

	var p3 string
	var g3 float64

	fmt.Println("Podaj trzeci przedmiot")
	fmt.Scan(&p3)
	fmt.Printf("Podaj liczbe godzin dla przedmiotu %s\n", p3)
	fmt.Scan(&g3)

	var u1, u2, u3 float64
	sum := g1 + g2 + g3
	u1 = 100.0 * g1 / sum
	u2 = 100.0 * g2 / sum
	u3 = 100.0 * g3 / sum

	fmt.Printf("Lista przedmiotow\n\n")
	fmt.Printf("%-25s | %-12s | %-10s\n", "Przedmiot", "Liczba godzin", "Udzial")
	fmt.Printf("%-25s | %-12dh | %-10.2f %% \n", p1, int(g1), u1)
	fmt.Printf("%-25s | %-12dh | %-10.2f %% \n", p2, int(g2), u2)
	fmt.Printf("%-25s | %-12dh | %-10.2f %% \n", p3, int(g3), u3)

	var nplik string
	fmt.Println("Podaj nazwe pliku")
	fmt.Scan(&nplik)

	plik, err := os.Create(nplik)
	if err != nil {
		panic(err)
	}

	defer plik.Close()

	fmt.Fprintf(plik, "Lista przedmiotow\n\n")
	fmt.Fprintf(plik, "%-25s | %-12s | %-10s\n", "Przedmiot", "Liczba godzin", "Udzial")
	fmt.Fprintf(plik, "%-25s | %-12dh | %-10.2f %% \n", p1, int(g1), u1)
	fmt.Fprintf(plik, "%-25s | %-12dh | %-10.2f %% \n", p2, int(g2), u2)
	fmt.Fprintf(plik, "%-25s | %-12dh | %-10.2f %% \n", p3, int(g3), u3)
	fmt.Fprintf(plik, "\n")
}
