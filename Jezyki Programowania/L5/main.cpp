#include "5.hpp"

int main() {
    Sim Stefan("Stefan", "Grziwuj", 19);
    Sim Andrzej("Andrzej", "Stefanski", 17);
    Sim Bartek;

    House house("Domek", 3);
    Stefan.addToHouse(house);
    Andrzej.addToHouse(house);
    Bartek.addToHouse(house);

    house.Print();
    Sim LepszyStefan(Stefan);

    Stefan.Vindicate();
    LepszyStefan.addToHouse(house);
    house.Print();
    return 0;
}