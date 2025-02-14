#include "7.hpp"

BodyPart::BodyPart(std::string vname, double vattribute, double vweight) {
    name = vname;
    attribute = vattribute;
    weight = vweight;
}

Creature::Creature(std::string vname) {
    name = vname;
    speed = 50;
    attack = 50;
    charm = 50;
    inteligence = 50;
    weight = 50;
}

std::string GetAttribute(std::string name) {
    if (name == "leg") { return "Speed: "; }
    if (name == "arm") { return "Attack: "; }
    if (name == "tail") { return "Charm: "; }
    if (name == "head") { return "Inteligence: "; }
    return "";
}

std::ostream& operator << (std::ostream& os, const BodyPart& p) {
    os<<"Name: "<<p.name<<" "<<GetAttribute(p.name)<<p.attribute<<" Weight: "<<p.weight<<std::endl;
    return os;
}

void BodyPart::Print() {
    std::cout<<*this;
}

bool BodyPart::operator == (const BodyPart sec) const {
    return name == sec.name && attribute == sec.attribute && weight == sec.weight;
}

void Creature::AddPart(const BodyPart& part) {
    parts.push_back(part);
    
    if (part.name == "leg") { speed += part.attribute; }
    if (part.name == "arm") { attack += part.attribute; }
    if (part.name == "tail") { charm += part.attribute; }
    if (part.name == "head") { inteligence += part.attribute; }

    weight += part.weight;
}

void Creature::RemovePart(const BodyPart& part) {
    parts.erase(std::remove(parts.begin(), parts.end(), part), parts.end());

    if (part.name == "leg") { speed -= part.attribute; }
    if (part.name == "arm") { attack -= part.attribute; }
    if (part.name == "tail") { charm -= part.attribute; }
    if (part.name == "head") { inteligence -= part.attribute; }

    weight -= part.weight;
}

std::ostream& operator << (std::ostream& os, const Creature& c) {
    os << "Name: "<<c.name<<", Speed: "<<c.speed<<", Attack: "
    <<c.attack<<", Charm: "<<c.charm<<", Intelligence: "<<c.inteligence
    <<", Weight: "<<c.weight;
    return os;
}

void Creature::Save(std::string name) {
    std::ofstream file(name);
    if(file.is_open()) {
        for (auto &bodypart : parts) {
            file<<bodypart;
        }
    }
    file.close();
}

void Creature::Load(std::string name) {
    std::ifstream file(name);
    if (file.is_open()) {


        std::string word, tmpA;
        double tmpB, tmpC;
        while(true) {

            file>>word;
            file>>tmpA;
            file>>word;
            file>>tmpB;
            file>>word;
            file>>tmpC;

            BodyPart tmp(tmpA, tmpB, tmpC);

            AddPart(tmp);

            if(file.eof()) { break; }
        }
    }
    file.close();
}

void Creature::Print() {
    std::cout<<*this<<std::endl<<std::endl;
}