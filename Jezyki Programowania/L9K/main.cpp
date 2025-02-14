#include "9.hpp"

int main() {
    Material Jajo("Jajo", 2);
    Material Pomidor("Pomidor"); // Bo tak
    Material Jajecznica("Jajecznica");

    Material DuzoJaj("Jajo", 7);
    Material BardzoDuzaJajecznicaDlaPudziana("Bardzo Duza Jajecznica Dla Pudziana");

    Material Azbest;
    Material Dach("Dach");

    Recipe R_Jajecznica(Jajo, Jajecznica);
    Recipe R_BardzoDuzaJajecznicaDlaPudziana(DuzoJaj, BardzoDuzaJajecznicaDlaPudziana);
    Recipe R_Dach(Azbest, Dach);

    Factory FabrykaJaj;
    FabrykaJaj.AddMaterial(Jajo);
    FabrykaJaj.AddMaterial(Jajo);

    FabrykaJaj.AddMaterial(Pomidor);
    FabrykaJaj.PrintStorage();

    FabrykaJaj(R_Jajecznica);
    FabrykaJaj(R_BardzoDuzaJajecznicaDlaPudziana);
    FabrykaJaj(R_Dach);

    FabrykaJaj.PrintStorage();


    return 0;
}