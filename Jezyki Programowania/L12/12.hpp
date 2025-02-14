#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <cmath>

class Stalker;

template<typename T>
class Backpack {
    std::vector<std::shared_ptr<T>> items;
    double weight;

    public:
    Backpack() { weight = 0; }
    ~Backpack() { }

    void Add(const std::shared_ptr<T>);
    void Remove(const std::string);
    void Print();

    int operator + (std::shared_ptr<T>);

    friend class Stalker;

};

class Item {
    protected:
    
    std::string name;
    double weight;

    public:
    
    Item(std::string = "jacekjaworek.exe", double = 2137);
    virtual ~Item() {};

    virtual void Print() = 0;
    int Weight() { return weight; }

    friend class Backpack<Item>;
};

class Weapon : public Item {
    double damage;

    public:
    Weapon(std::string = "Katana", double = 3, double = 25);
    ~Weapon() { }

    void Print();
};

class Artifact : public Item {
    std::string effect;
    double effectVal;

    public:
    Artifact(std::string = "Zlote jajo", double = 8, std::string = "Ochrona", double = 25);
    ~Artifact() { }

    void Print();
};

class Stalker {
    std::string name;
    Backpack<Item> backpack;
    double limit;

    public:
    Stalker(std::string = "Stefan", double limit = 10);
    ~Stalker() {}

    void operator += (std::shared_ptr<Item>);
    void operator -= (std::string);

    void Print();
};