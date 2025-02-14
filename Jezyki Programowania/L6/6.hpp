#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

class Squad;

enum Class {
    Assault, Sniper, Rifleman, Engineer
};

class Soilder {
    std::string firstname, lastname;
    double level;
    
    Class _class;
    double vitality;
    double mobility;
    bool weaponHandling;

    public:

    static int minlevel;
    static int maxlevel;

    Soilder(std::string fn = "", std:: string ln = "");
    ~Soilder() {};

    bool operator > (const Soilder) const;
    bool operator < (const Soilder) const;
    bool operator == (const Soilder) const;

    static void setminlevel (int i) {minlevel = i;}
    static void setmaxlevel (int i) {maxlevel = i;}

    friend std::ostream& operator << (std::ostream&, const Soilder&);
    friend class Squad;
};

class Squad {
    std::string name;
    std::vector<Soilder> Soilders;

    public:

    Squad(std::string _name = "Orzel 1");
    ~Squad() {};

    void operator += (Soilder);
    void operator -= (Soilder);

    void Rank(std::string);
    void Print();
};

int Rand(int, int);

std::ostream& operator << (std::ostream&, const Soilder&);

