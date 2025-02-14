#include "12.hpp"

int main() {

    Stalker Domino("Domino");

    Weapon Katana;
    Artifact Jajo;

    Domino += std::make_shared<Weapon>(Katana);
    Domino += std::make_shared<Artifact>(Jajo);

    Domino -= "Katana";
    Domino += std::make_shared<Artifact>(Jajo);

    Domino.Print();

    return 0;
}