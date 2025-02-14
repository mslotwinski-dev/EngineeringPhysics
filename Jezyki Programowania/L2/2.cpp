#include "2.hpp"
using namespace std;

int main() {
    Player Bogdan("Bogdan", 213.7);

    Demon Andrzej(6, true);
    Demon Stefan(66, true);
    Demon Domino(666, true);

    Demon Demony[] = {Stefan, Andrzej, Domino};

    fight(Bogdan, Demony);


    return 0;
}