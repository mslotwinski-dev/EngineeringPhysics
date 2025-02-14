#include "8.hpp"

Present::Present(std::string _name, double _weight) {
    name = _name;
    weight = _weight;
}

void Present::Print() {
    std::cout<<name<<": "<<weight<<std::endl;
}

bool Present::operator == (const Present p) const {
    return name == p.name && weight == p.weight;
}

void Tree::Print() {
    std::cout<<"Choinka"<<std::endl;
    std::cout<<"Ilosc prezentow: "<<presents.size()<<" z "<<capacity<<std::endl;
    for (auto &present : presents) {
        present.Print();
    }
    std::cout<<std::endl;
}

void Tree::operator+= (Present present) {
    if (capacity > presents.size()) {
        presents.push_back(present);
    } else {
        std::cout<<"Nic wiecej sie tu nie zmiesci."<<std::endl;
    }
}

Present Tree::operator-= (Present present) {
    presents.erase(std::remove(presents.begin(), presents.end(), present), presents.end());

    return present;
}

void Grinch::Print() {
    std::cout<<"Grinch"<<std::endl;
    std::cout<<"Ilosc prezentow: "<<bag.size()<<std::endl;
    for (auto &present : bag) {
        present.Print();
    }
    std::cout<<std::endl;
}

void Grinch::StealChristmas(Tree& tree) {
    while (tree.HasPresents()) {
        Present present = tree.GrabPresent();

        if (present._weight() > energy) { break; }
        
        bag.push_back(tree -= present);
        energy -= present._weight();
    }
}