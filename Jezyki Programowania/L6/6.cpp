#include "6.hpp"

int Soilder::minlevel = 1;
int Soilder::maxlevel = 5;

int Rand(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

Soilder::Soilder(std::string fn, std::string ln) {
    firstname = fn;
    lastname = ln;
    level = (double)Rand(100*minlevel, 100*maxlevel)/100;

    _class = Assault;

    switch(_class) {
        case Assault: {
            vitality = 50;
            mobility = 100;
            weaponHandling = true;
            break;
        }
        case Sniper: {
            vitality = 40;
            mobility = 20;
            weaponHandling = true;
            break;
        }
        case Rifleman: {
            vitality = 40;
            mobility = 80;
            weaponHandling = true;
            break;
        }
        case Engineer: {
            vitality = 80;
            mobility = 50;
            weaponHandling = false;
            break;
        }
    }
}

Squad::Squad(std::string _name) {
    name = _name;
}

bool Soilder::operator > (const Soilder torpedal) const {
    return level > torpedal.level;
}

bool Soilder::operator < (const Soilder torpedal) const {
    return level < torpedal.level;
}

bool Soilder::operator == (const Soilder torpedal) const {
    return firstname == torpedal.firstname && lastname == torpedal.lastname && level == torpedal.level;
}

std::ostream& operator << (std::ostream& os, const Soilder& s) {
    std::string arr[4] = {"Assault", "Sniper", "Riffleman", "Engineer"};
    
    os << "Name: "<<s.firstname<<", Lastname: "<<s.lastname<<", Level: "<<s.level<<", Class: "<<arr[s._class]<<", Vitality: "<<s.level<<", Mobility: "<<s.level<<", Weapon Handling: "<<s.level;
    return os;
}

void Squad::operator += (Soilder s) {
    Soilders.push_back(s);
}

void Squad::operator -= (Soilder s) {
    Soilders.erase(std::remove(Soilders.begin(), Soilders.end(), s), Soilders.end());
}

void Squad::Rank(std::string mode) {
    if (mode == "<") {
        std::sort(Soilders.begin(), Soilders.end());
    } else if (mode == ">") {
       std::sort(Soilders.begin(), Soilders.end(), std::greater<Soilder>()); 
    }
}

void Squad::Print() {
    std::cout<<"____"<<name<<"____"<<std::endl;
    for (auto &s : Soilders) {
        std::cout<<s<<std::endl;
    }
    std::cout<<std::endl;
}