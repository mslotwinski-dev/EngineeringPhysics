#include "8.hpp"

int main() {
    Present Wegiel;
    Present Jajo("Jajo", 1);
    Present DokladnaLokalizacjaPobytuJackaJaworka("Dokladna Lokalizacja Pobytu Jacka Jaworka", 2);
    Present CementUdajacyMefedron("Mefefron", 4);

    Tree Drzewko1;
    Tree Drzewko2;

    Drzewko1 += Wegiel;
    Drzewko1 += Jajo;
    Drzewko1.Print();

    Drzewko2 += Wegiel;
    Drzewko2 += Jajo;
    Drzewko2 += DokladnaLokalizacjaPobytuJackaJaworka;
    Drzewko2 += CementUdajacyMefedron;
    Drzewko2.Print();

    Grinch N;
    N.Print();
    N.StealChristmas(Drzewko1);
    N.Print();
    N.StealChristmas(Drzewko2);
    N.Print();

    return 0;
}