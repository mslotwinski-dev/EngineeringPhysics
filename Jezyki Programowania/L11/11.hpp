#include <iostream>
#include <vector>
#include <algorithm>

class Steve;

class Object {
    protected: 
    
    std::string name;
    int amount;
    Steve* owner;

    public:

    Object(int a = 64) { amount = a; }
    virtual ~Object() {}

    virtual void Use() = 0;
    virtual void Print() = 0;

    void Added(Steve*);

    friend bool operator == (Object*, const std::string&);
    
    friend class Steve;
};

bool operator == (Object*, const std::string&);

class Block : public Object {
    int hardeness;
    bool isFlameable;

    public:

    Block(std::string = "Coal ore", int = 64, int = 10, bool = true);
    ~Block() {}

    void Use();
    void Print();
};

class Item : public Object {
    protected:
    bool isEnchanted;
    
    public:

    Item(std::string = "Coal", int = 64, bool = false);
    virtual ~Item() {};

    void Use();
    void Print();
};

class Food : public Item {
    double _health;
    double _hunger;

    public:
    Food(std::string = "Coal", int = 64, bool = false, double = 5, double = 5);
    ~Food() {}

    void Use();

};

class Steve {
    std::vector<Object*> backpack;
    double hunger;
    double health;

    public:
    Steve(double = 5, double = 5);
    ~Steve() { };

    void UseObject(std::string name);
    void Print();

    void operator += (Object*);

    friend class Object;
    friend class Food;
};