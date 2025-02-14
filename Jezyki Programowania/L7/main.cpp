#include "7.hpp"

int main() {
    Creature Stefan("Stefan");
    
    BodyPart Leg1("leg");
    BodyPart Leg2("leg", 30);
    BodyPart Wing1("leg", 70);
    BodyPart Wing2("leg", 70);

    BodyPart Arm1("arm", 40);
    BodyPart Arm2("arm", 40);

    BodyPart Tail("tail", 50);
    BodyPart Horns("tail", 150);

    BodyPart Head("head", 150);

    Stefan.AddPart(Leg1);
    Stefan.AddPart(Leg2);
    Stefan.AddPart(Wing1);
    Stefan.AddPart(Wing2);
    Stefan.AddPart(Arm1);
    Stefan.AddPart(Arm2);
    Stefan.AddPart(Tail);
    Stefan.AddPart(Head);

    Stefan.Print();

    Stefan.Save("./2137.txt");

    Creature Zbigniew("Zbigniew Kucharski");
    Zbigniew.Load("./2137.txt");

    Zbigniew.RemovePart(Wing1);
    Zbigniew.RemovePart(Wing2);
    Zbigniew.AddPart(Horns);

    Zbigniew.Print();

    return 0;
}