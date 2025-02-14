#include "5.hpp"

void Sim::addToHouse(House &h) {
    if (h.getNsims() < h.gcapacity()) {
        house = &h;
        h.AddSim(this);
    } else {
        std::cout<<"Brak miejsca"<<std::endl;
    }
}

void Sim::Vindicate() {
    house->RemoveSim(this);
    house = nullptr;
}

void Sim::Print() {
    std::cout<<"Imie:"<<firstname<<std::endl;
    std::cout<<"Nazwisko:"<<lastname<<std::endl;
    std::cout<<"Wiek:"<<age<<std::endl;
    if (house) {
        // std::cout<<"Dom:"<<house<<std::endl;
    } else {
        std::cout<<"Bezdomny"<<std::endl;
    }
    std::cout<<std::endl;

}

void House::Print() {
    std::cout<<"_______________________"<<std::endl;

    for(Sim* s : sims) {
        s->Print();
    }

}
