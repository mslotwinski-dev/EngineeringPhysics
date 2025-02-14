#include <iostream>
#include <vector>

class Bloon {
    int hp;
    bool status;

    public:

    Bloon(int = 2, bool = true);
    ~Bloon() {}

    bool Update();
    
    bool operator -= (int);
};

class Monkey {
    protected:
    
    std::string name;
    int damage;
    int rate;
    int kills;

    public:

    Monkey(std::string = "Stefan", int = 1, int = 5);
    ~Monkey() {}

    void Print();
    void Fight(std::vector<Bloon>);
};

class SuperMonkey : public Monkey {
    private:
    int damageMod;

    public:
    SuperMonkey(std::string = "Super Stefan", int = 1, int = 20, int = 1);
    ~SuperMonkey() {}

    void Print();
    void Fight(std::vector<Bloon>);
};


class BoomerangMonkey : public Monkey {
    private:
    int pierce;

    public:
    BoomerangMonkey(std::string = "Stefan z Boomerangiem", int = 1, int = 5, int = 2);
    ~BoomerangMonkey() {}

    void Print();
    void Fight(std::vector<Bloon>);
};