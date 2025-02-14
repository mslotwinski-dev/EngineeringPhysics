#include "6.hpp"

int main() {
    Squad Orzel1("Orzel 1");
    Squad Orzel2("Orzel 2");

    Soilder Stefana("Stefan", "A");
    Soilder Stefanb("Stefan", "B");
    Soilder Stefanc("Stefan", "C");
    Soilder Stefand("Stefan", "D");
    Soilder Stefane("Stefan", "E");
    Soilder Stefanf("Stefan", "F");
    Soilder Stefang("Stefan", "G");

    Orzel1 += Stefana;
    Orzel1 += Stefanb;
    Orzel1 += Stefanc;
    Orzel1 += Stefand;

    Orzel2 += Stefane;
    Orzel2 += Stefanf;
    Orzel2 += Stefang;

    Orzel1.Print();
    Orzel2.Print();

    Orzel1.Rank(">");
    Orzel2.Rank(">");

    Orzel1.Print();
    Orzel2.Print();
    return 0;
}