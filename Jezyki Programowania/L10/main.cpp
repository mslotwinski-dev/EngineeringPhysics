#include "10.hpp"

int main() {
    Bloon bloon;
    std::vector<Bloon> bloons(20, bloon);
    
    Monkey Stefan;
    SuperMonkey SuperStefan;
    BoomerangMonkey BoomerStefan;

    Stefan.Fight(bloons);
    SuperStefan.Fight(bloons);
    BoomerStefan.Fight(bloons);

    Stefan.Print();
    SuperStefan.Print();
    BoomerStefan.Print();

    return 0;
}