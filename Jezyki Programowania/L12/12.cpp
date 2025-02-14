#include "12.hpp"

Item::Item(std::string name, double weight) {
    this->name = name;
    this->weight = weight;
}

Weapon::Weapon(std::string name, double weight, double damage) {
    this->name = name;
    this->weight = weight;
    this->damage = damage;
}

void Weapon::Print() {
    std::cout<<name<<" ("<<weight<<") - Obrazenia: "<<damage<<std::endl;
}

Artifact::Artifact(std::string name, double weight, std::string effect, double effectVal) {
    this->name = name;
    this->weight = weight;
    this->effect = effect;
    this->effectVal = effectVal;
}

void Artifact::Print() {
    std::cout<<name<<" ("<<weight<<") - "<<effect<<": "<<effectVal<<std::endl;
}

template <class T>
void Backpack<T>::Add(std::shared_ptr<T> a) {
    items.push_back(a);
    weight += a->weight;
}

template <class T>
void Backpack<T>::Remove(std::string a) {
    auto fun = [a](std::shared_ptr<T> sensowniejszy_obiektplecakowy) {
        return sensowniejszy_obiektplecakowy->name == a;
    };

    auto item = find_if(items.begin(), items.end(), fun);

    if (item != items.end()) {
        weight -= (*item)->weight;
        items.erase(item);
    } else {
        std::cout<<"Nie znaleziono przedmiotu o nazwie "<<a<<std::endl;
    }
}

template <class T>
void Backpack<T>::Print() {
    for (auto i : items) {
        i->Print();
    }

    std::cout<<std::endl;
}

template <class T>
int Backpack<T>::operator + (std::shared_ptr<T> a) {
    return weight + a->weight;
}

Stalker::Stalker(std::string name, double limit) {
    this->name = name;
    this->limit = limit;
}

void Stalker::operator += (std::shared_ptr<Item> item) {
    if (backpack + item <= limit) {
        backpack.Add(item);
    } else {
        std::cout<<"Przekroczono limit"<<std::endl;
    }
}

void Stalker::operator -= (std::string s) {
    backpack.Remove(s);
}

void Stalker::Print() {
    std::cout<<"Imie: "<<name<<", Obciazenie: "<<backpack.weight<<" ("<<std::floor(100*backpack.weight / limit)<<"%)"<<std::endl;
    std::cout<<"Zawartosc: "<<std::endl;
    backpack.Print();
}
