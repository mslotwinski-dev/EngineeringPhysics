package main

import "fmt"

func main() {
	var a float64
	var b float64

	fmt.Println("Podaj a i b")
	fmt.Scanln(&a)
	fmt.Scanln(&b)

	if a != 0 {
		fmt.Printf("%.3f\n", -b/a)
	} else if b != 0 {
		fmt.Println("Brak")
	} else {
		fmt.Println("Nieskocznosc rozwiazan")
	}

}
