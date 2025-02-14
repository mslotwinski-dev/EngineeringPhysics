#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Creature;

class BodyPart {
    std::string name;
    double attribute,weight;

    public: 
    BodyPart(std::string name, double attribute = 20, double weight = 20);
    ~BodyPart() {};

    void Print();

    bool operator == (const BodyPart) const;

    friend class Creature;
    friend std::ostream& operator << (std::ostream&, const BodyPart&);
};

class Creature {
    std::string name;
    double speed, attack, charm, inteligence, weight;
    std::vector<BodyPart> parts;

    public: 
    Creature(std::string name);
    ~Creature() {};

    void AddPart(const BodyPart&);
    void RemovePart(const BodyPart&);
    void Save(std::string);
    void Load(std::string);
    void Print();

    friend std::ostream& operator << (std::ostream&, const Creature&);
};

std::ostream& operator << (std::ostream&, const BodyPart&);
std::ostream& operator << (std::ostream&, const Creature&);

std::string GetAttribute(std::string name);