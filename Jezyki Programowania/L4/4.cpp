#include "4.hpp"

int main() {
    Squad SQ1(20);
    Squad SQ2(20);


    Hatchery H(400);

    SQ1.ChaoticFight(H);
    Marine::useSteamPack();
    SQ2.ChaoticFight(H);

    return 0;
}