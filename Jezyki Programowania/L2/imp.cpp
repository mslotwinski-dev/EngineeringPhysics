#include "2.hpp"
using namespace std;

Player::Player(string name, double hp) {
    _name = name;
    _hp = hp;
};

Demon::Demon(double dmg, double isAlive) {
    _dmg = dmg;
    _isAlive = isAlive;
};

bool fight(Player& player, Demon (&demons)[]) {

    int killed = 0;

    for (int i = 0; i < 3; i++) {
        if (!demons[i].isAlive() || player.hp() <= 0) {
            cout<<"Walka nie ma sensu"<<endl;
            return false;
        }

        player.vhp(player.hp() - demons[i].dmg());

        if (player.hp() > 0) {
            cout<<"Walka zostala wygrana"<<endl;

            demons[i].kill();
            killed++;
            continue;
        };

        cout<<"Walka zostala przegrana"<<endl;

        cout<<"Zabito "<<killed<<" demonow"<<endl;
        return false;
    }
    
    return true;
};