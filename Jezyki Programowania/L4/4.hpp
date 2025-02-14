#include <iostream>
#include <vector>

class Zerg {
    double hp, strength;

    public:
    Zerg(double _hp = 40, double _strength = 5);
    ~Zerg() {}

    double vhp() {
        return hp;
    }

    void vhp(double _hp) {
        hp = _hp;
    }

    double vstrength() {
        return hp;
    }

    int getInitiative();

    friend class Hatcher;

};


class Marine {
    double hp, strength;
    static bool boost;

    public:
    Marine(double _hp = 100, double _strength = 10);
    ~Marine() {}

    double vhp() {
        return hp;
    }

    void vhp(double _hp) {
        hp = _hp;
    }

    double vstrength() {
        return boost ? 5*strength: strength;
    }

    static void useSteamPack() {
        boost = true;
    }

    int getInitiative();

    friend class Squad;
};

class Hatchery {
    public:
    double maxHP;
    std::vector<Zerg> zergs;
    Hatchery(int j = 200);
    ~Hatchery() {}

    bool isDestroyed() {
        return zergs.size() == 0;
    }

    
};

class Squad {
    public:
    double maxHP;
    std::vector<Marine> marines;
    Squad(int j = 10);
    ~Squad() {}

    bool isDead() {
        return marines.size() == 0;
    }

    void Fight(Hatchery &hatch);
    void ChaoticFight(Hatchery &hatch);

    
};



