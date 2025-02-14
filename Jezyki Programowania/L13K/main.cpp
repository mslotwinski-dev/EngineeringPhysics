#include "13.hpp"

int main() {
    RaceCar Fiat126p ("Fiat126p");
    RaceCar BMWSzybkie;
    
    Part Silnik;

    BMWSzybkie + Silnik;

    PoliceCar policja;

    policja.Chase(Fiat126p);
    policja.Chase(BMWSzybkie);

    Fiat126p.Print();
    BMWSzybkie.Print();
    policja.Print();

    return 0;
}