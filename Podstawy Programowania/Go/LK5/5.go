package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sms := ""

	for true {
		fmt.Println("Wybierz operacje")
		fmt.Println("1. Wczytaj sms i wypisz go")
		fmt.Println("2. Szyfruj sms i wypisz go")
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
				fmt.Println("Wpisz tresc sms znak po znaku")

				// for true {
				// 	var c rune
				// 	fmt.Scanf("%c", &c)
				// 	fmt.Println(c)

				// 	if c == 27 {
				// 		goto exit
				// 	} else {
				// 		sms = append(sms, c)
				// 	}
				// }

				// exit:

				in := bufio.NewReader(os.Stdin)

				sms, _ = in.ReadString('\n')

				fmt.Println("Jawna tresc sms")
				fmt.Println(sms)

				// fmt.Println("Kod sms w postaci znakow ASCII")
				// for i := 0; i <= len(sms); i++ {
				// 	fmt.Printf("%d", sms[i])
				// }
				// fmt.Printf("\n")
			}

			// case 2: {
			// 	int v;
			// 	char* szyfr = (char*)calloc(sizeof(char), strlen(sms) + 1);
			// 	strcpy (szyfr, sms);
			// 	puts("Wybierz wartosc przesuniecia");
			// 	scanf("%d", &v);

			// 	for (int i = 0; i <= strlen(sms); i++) {
			// 		// WIELKIE
			// 		if (szyfr[i] >= 65 && szyfr[i]<= 90) {
			// 			if (szyfr[i] > 90 - v) szyfr[i] -= 26;
			// 			szyfr[i] += v;
			// 		}

			// 		// MALE
			// 		if (szyfr[i] >= 97 && szyfr[i]<= 122) {
			// 			if (szyfr[i] > 122 - v) szyfr[i] -= 26;
			// 			szyfr[i] += v;
			// 		}

			// 		// CYFRY
			// 		if (szyfr[i] >= 48 && szyfr[i]<= 57) {
			// 			if (szyfr[i] >= 57 - v) szyfr[i] -= 10;
			// 			szyfr[i] += v;
			// 		}

			// 	}

			// 	puts("Zaszyfrowana wiadomosc to");
			// 	puts(szyfr);

			// 	break;
			// }
		}

	}
}
