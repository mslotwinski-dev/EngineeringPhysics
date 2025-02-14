#include "4.hpp"

bool Marine::boost = false;

Zerg::Zerg(double _hp, double _strength) {
    hp = _hp;
    strength = _strength;
}

Marine::Marine(double _hp, double _strength) {
    hp = _hp;
    strength = _strength;
}

Hatchery::Hatchery(int j) {
    for (int i = 0; i < j; i++) {
        Zerg Fregata;
        zergs.push_back(Fregata);
        if (i==0) {maxHP = Fregata.vhp(); }
    }


}

Squad::Squad(int j) {
    for (int i = 0; i < j; i++) {
        Marine Okret;
        marines.push_back(Okret);
        if (i==0) {maxHP = Okret.vhp(); }
    }
}

void Squad::Fight(Hatchery &hatch) {
    int killed = 0;
    int died = 0;


    while (!hatch.isDestroyed() && !isDead()) {
        marines[0].hp -= hatch.zergs[0].vstrength();
           
        if (marines[0].vhp() <= 0) {
            marines.erase(marines.begin());
            died++;
        }

        hatch.zergs[0].vhp(hatch.zergs[0].vhp() - marines[0].vstrength());

        if (hatch.zergs[0].vhp() <= 0) {
            hatch.zergs.erase(hatch.zergs.begin());
            killed++;
        }

    }

    std::cout<<"Ilosc zabitych: "<<killed<<std::endl;
    std::cout<<"Ilosc ofiar: "<<died<<std::endl;
}

int Zerg::getInitiative() {
    return 4+rand()%12;
}

int Marine::getInitiative() {
    return boost ? 4+rand()%12: 4+rand()%20;
}

void Squad::ChaoticFight(Hatchery &hatch) {
    int killed = 0;
    int died = 0;


    while (!hatch.isDestroyed() && !isDead()) {
        int zergid = rand()%(hatch.zergs.size()-0 + 1) + 0;
        int marineid = rand()%(marines.size()-0 + 1) + 0;

        int marineinit = marines[marineid].getInitiative();
        int zerginit = hatch.zergs[zergid].getInitiative();

        double x = zerginit / marineinit;

        if (marineinit > zerginit) {

            for (int i = 0; i <= x; i++ ) {
            
                hatch.zergs[zergid].vhp(hatch.zergs[zergid].vhp() - ((double)marineinit/6)*marines[marineid].vstrength()*marines[marineid].hp/maxHP);

                if (hatch.zergs[zergid].vhp() <= 0) {
                    hatch.zergs.erase(hatch.zergs.begin() +zergid);
                    killed++;
                }
            }

            for (int i = 0; i <= 1/x; i++ ) {

                marines[marineid].hp -= (Marine::boost ? 2 : 1)*((double)zerginit/3)*hatch.zergs[zergid].vstrength()*hatch.zergs[zergid].vhp()/hatch.maxHP;

                if (marines[0].vhp() <= 0) {
                    marines.erase(marines.begin() + marineid);
                    died++;
                }
            }
        } else {

            
            for (int i = 0; i <= 1/x; i++ ) {
                marines[marineid].hp -= (Marine::boost ? 2 : 1)*((double)zerginit/3)*hatch.zergs[zergid].vstrength()*hatch.zergs[zergid].vhp()/hatch.maxHP;
                
                if (marines[0].vhp() <= 0) {
                    marines.erase(marines.begin() + marineid);
                    died++;
                }

            }

            for (int i = 0; i <= x; i++ ) {

                hatch.zergs[zergid].vhp(hatch.zergs[zergid].vhp() - ((double)marineinit/6)*marines[marineid].vstrength()*marines[marineid].hp/maxHP);

                if (hatch.zergs[zergid].vhp() <= 0) {
                    hatch.zergs.erase(hatch.zergs.begin() +zergid);
                    killed++;
                }
            }

        }





    }

    std::cout<<"Ilosc zabitych: "<<killed<<std::endl;
    std::cout<<"Ilosc ofiar: "<<died<<std::endl;
}