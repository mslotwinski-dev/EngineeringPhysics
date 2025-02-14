#include <iostream>
#include <vector>

class Player;

class Food {
    double hunger, hydration;

    public:
    Food(double _hunger = 50, double _hydration = 50);
    ~Food();

    friend class Player;
};

class Medication {
    double health, sanity;

    public:
    Medication(double _health = 50, double _sanity = 50);
    ~Medication();

    friend class Player;
};

class Plecak {
    std::vector<Food> food;
    std::vector<Medication> med;
    
    public:
    Plecak();
    ~Plecak();

    void Add(Food food);
    void Add(Medication med);

    friend class Player;
};

class Player {
    std::string name;
    double hunger, hydration, health, sanity;

    public:
    Player(double _hunger = 50, double _hydration = 50, double _health = 50, double _sanity = 50);
    ~Player();

    void Use(Food food);
    void Use(Medication medication);
    void Print();

    void Feed (Plecak &plecak);
    void Heal (Plecak &plecak);
};

double Gap(double &v);
