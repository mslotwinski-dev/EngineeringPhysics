#include <iostream>
#include <vector>

using namespace std;

class Player {
    string _name;
    double _hp;
    
    public:
        string name() {return _name;}
        double hp() {return _hp;}

        void vname(string name) {_name = name;}
        void vhp(double hp) {_hp = hp;}

        Player(string name, double hp = 100);
};

class Demon {
    double _dmg;
    bool _isAlive;
    
    public:   
        double dmg() {return _dmg;}
        bool isAlive() {return _isAlive;}

        void vdmg(double dmg) {_dmg = dmg;}
        void kill() {_isAlive = false;}
        
        Demon(double dmg, double isAlive = false);
};

bool fight(Player& player, Demon (&demons)[]);