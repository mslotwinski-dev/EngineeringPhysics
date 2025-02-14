#include <iostream>
#include <set>

class House;

class Sim {
    const std::string firstname, lastname;
    std::string mood;
    int age;
    House *house;
    
    public:
    Sim(std::string firstname = "Bartosz", std::string lastname = "Walaszek", int age = 40) : firstname(firstname), lastname(lastname), age(age) { }
    Sim(const Sim& s) : firstname(s.firstname), lastname(s.lastname), age(s.age) {} ;
    ~Sim() {};

    std::string gfirstname() const { return firstname; }
    std::string glastname() const { return lastname; }

    void addToHouse(House &house);
    void Vindicate();
    void Print();

    
};

class House {
    const std::string adress;
    const int capacity;
    std::set<Sim*> sims; 
 
    public:
    House(std::string adress = "Wadowice", int capacity = 5) : adress(adress), capacity(capacity) {};
    ~House() {};

    std::string gadress() const { return adress; }
    int gcapacity() const { return capacity; }

    int getNsims() {return sims.size(); }
    void AddSim(Sim* sim) { sims.insert(sim); };
    void RemoveSim(Sim* sim) { sims.erase(sim); };
    void Print();

};

