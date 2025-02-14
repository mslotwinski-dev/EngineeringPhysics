#include "11.hpp"

int main() {
    Block CoalOre;
    Block Ice("Ice", 1, 2, false);
    Item Coal;

    Steve Player;

    Player += &CoalOre;
    Player += &Ice;
    Player += &Coal;

    Player.Print();

    Player.UseObject("Coal ore");
    Player.UseObject("Ice");
    Player.UseObject("Coal");

    std::cout<<std::endl;

    Player.Print();

    return 0;
}