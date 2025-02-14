#include "11.hpp"

void Object::Added(Steve* s) {
    owner = s;
}

bool operator == (Object* obj, const std::string& s) {
    return obj->name == s;
}

Block::Block(std::string name, int amount, int hardeness, bool isFlameable) {
    this->name = name;
    this->amount = amount;
    this->hardeness = hardeness;
    this->isFlameable = isFlameable;
}

void Block::Use() {
    if (amount == 0) { return; }

    std::cout<<"Steve stawia blok "<<name<<" o twardosci "<<hardeness<<", ktory ";
    if (!isFlameable) { std::cout<<"nie "; }
    std::cout<<"jest latwopalny."<<std::endl;

    amount--;
}

void Block::Print() {
    std::cout<<name<<":  ilosc ("<<amount<<"), twardosc ("<<hardeness<<")";
    if (isFlameable) { std::cout<<", latwopalny"; }
    std::cout<<std::endl;
}

Item::Item(std::string name, int amount, bool isEnchanted) {
    this->name = name;
    this->amount = amount;
    this->isEnchanted = isEnchanted;
}

void Item::Use() {
    if (amount == 0) { return; }

    std::cout<<"Steve uzywa ";
    if (!isEnchanted) { std::cout<<"zenchantowanego "; }
    std::cout<<name<<std::endl;

    amount--;
}

void Item::Print() {
    std::cout<<name;
    if (isEnchanted) { std::cout<<" (enchantowany)"; }
    std::cout<<": ilosc ("<<amount<<")"<<std::endl;
}

Steve::Steve(double hunger, double health) {
    this->hunger = hunger;
    this->health = health;
}

void Steve::operator += (Object* s) {
    backpack.push_back(s);
    s->Added(this);
}

void Steve::UseObject(std::string _name) {
    auto index = std::find(backpack.begin(), backpack.end(), _name);

    if (index == backpack.end()) {
        std::cout<<"Brak objektu o nazwie "<<_name<<std::endl;
        return;
    }

    (*index)->Use();
    
    if ((*index)->amount == 0) {
        backpack.erase(index);
    }
}

void Steve::Print() {
    std::cout<<"Plecak Steve'a"<<std::endl;
    for (auto i : backpack) {
        i->Print();
    }
    std::cout<<std::endl;
}

Food::Food(std::string name, int amount, bool isEnchanted, double health, double hunger) {
    this->name = name;
    this->amount = amount;
    this->isEnchanted = isEnchanted;
    this->_health = health;
    this->_hunger = hunger;
}


void Food::Use() {
    if (amount == 0) { return; }

    std::cout<<"Steve uzywa ";
    if (!isEnchanted) { std::cout<<"zenchantowanego "; }
    std::cout<<name<<"o wartosci leczenia zycia "
    <<_health<<" oraz glodu"<<_hunger<<std::endl;

    owner->health += _health;
    owner->hunger += _hunger;

    if (owner-> health > 10) {
        owner->health = 10;
    }

    if (owner-> hunger > 10) {
        owner-> hunger = 10;
    }

    amount--;
}