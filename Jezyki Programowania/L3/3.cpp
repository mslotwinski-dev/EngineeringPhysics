#include "3.hpp"

int main() {
    Player Stefan;

    Food Truskawka; 
    Food Chleb(70, 10);
    Food Arbuz(20, 65);
    Food Woda(0, 100);

    Stefan.Use(Truskawka);
    Stefan.Use(Chleb);
    Stefan.Use(Arbuz);
    Stefan.Use(Woda);

    

    return 0;
}