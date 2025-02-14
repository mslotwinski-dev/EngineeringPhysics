#include "10.hpp"

Bloon::Bloon(int hp, bool status) {
    this->hp = hp;
    this->status = status;
}

bool Bloon::operator-= (int dmg) {
    hp -= dmg;
    return !Update(); // killed ?
}

bool Bloon::Update() {
    if (hp <= 0) { status = false; }
    return status;
}


Monkey::Monkey(std::string name, int dmg, int rate) {
    this->name = name;
    this->damage = dmg;
    this->rate = rate;
    kills = 0;
}

void Monkey::Print() {
    std::cout<<"Malpka "<<name<<std::endl;
    std::cout<<"Damage: "<<damage<<std::endl;
    std::cout<<"Attack rate: "<<rate<<std::endl;
    std::cout<<"Kills: "<<kills<<std::endl;
    std::cout<<std::endl;
}

void Monkey::Fight(std::vector<Bloon> bloons) {
    for (int i = 0; i < rate; i++) {
        if(!bloons.size()) { break; }
        if (bloons[0] -= damage) {
            bloons.erase(bloons.begin());
            kills++;
        }
    }
}

SuperMonkey::SuperMonkey(std::string name, int dmg, int rate, int damageMod) {
    this->name = name;
    this->damage = dmg;
    this->rate = rate;
    this->damageMod = damageMod;
    kills = 0;
}

void SuperMonkey::Print() {
    std::cout<<"Super Malpka "<<name<<std::endl;
    std::cout<<"Damage: "<<damage<<std::endl;
    std::cout<<"Attack rate: "<<rate<<std::endl;
    std::cout<<"Kills: "<<kills<<std::endl;
    std::cout<<std::endl;
}

void SuperMonkey::Fight(std::vector<Bloon> bloons) {
    for (int i = 0; i < rate; i++) {
        if(!bloons.size()) { break; }
        if (bloons[0] -= damage * damageMod) {
            bloons.erase(bloons.begin());
            kills++;
        }
    }
}

BoomerangMonkey::BoomerangMonkey(std::string name, int dmg, int rate, int pierce) {
    this->name = name;
    this->damage = dmg;
    this->rate = rate;
    this->pierce = pierce;
    kills = 0;
}

void BoomerangMonkey::Print() {
    std::cout<<"Malpka "<<name<<" (z Boomerangiem)"<<std::endl;
    std::cout<<"Damage: "<<damage<<std::endl;
    std::cout<<"Attack rate: "<<rate<<std::endl;
    std::cout<<"Kills: "<<kills<<std::endl;
    std::cout<<std::endl;
}

void BoomerangMonkey::Fight(std::vector<Bloon> bloons) {
    for (int i = 0; i < rate; i++) {
        if(!bloons.size()) { break; }
        for (int j = 0; j < pierce; j++) {
            if(bloons.size() > j) {
                if (bloons[j] -= damage) {
                    bloons.erase(bloons.begin());
                    kills++;
                }
            }
            
        }
    }
}