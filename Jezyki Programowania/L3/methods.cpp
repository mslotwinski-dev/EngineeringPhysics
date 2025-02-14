#include "3.hpp"

double Gap(double &v) {
    if (v < 0) {
        return 0;
    }

    if (v > 100) {
        return 100;
    }

    return v;
}

Player::Player(double _hunger, double _hydration, double _health, double _sanity) {
    hunger = _hunger;
    hydration = _hydration;
    health = _health;
    sanity = _sanity;
}

Player::~Player() {}

void Player::Use(Food food) {
    hunger += food.hunger;
    hydration += food.hydration;
    Gap(hunger);
    Gap(hydration);
}

void Player::Use(Medication medication) {
    health += medication.health;
    sanity += medication.sanity;
    Gap(health);
    Gap(sanity);
}

void Player::Print() {
    std::cout<<"Stats"<<std::endl;

    std::cout<<"Hunger: "<<hunger<<std::endl;
    std::cout<<"Hydration: "<<hydration<<std::endl;
    std::cout<<"Health: "<<health<<std::endl;
    std::cout<<"Sanity: "<<sanity<<std::endl;
}

void Player::Feed(Plecak &plecak) {
    while (true) {
        if (hunger != 100 || hydration != 100) {
            break;
        }

        Use(plecak.food.back());
        plecak.food.pop_back();
    }
}

void Player::Heal(Plecak &plecak) {
        while (true) {
        if (health != 100 || sanity != 100) {
            break;
        }

        Use(plecak.med.back());
        plecak.med.pop_back();
    }
}

Plecak::Plecak() {}

Plecak::~Plecak() {}

void Plecak::Add(Food food) {
    Plecak::food.push_back(food);
}

void Plecak::Add(Medication med) {
    Plecak::med.push_back(med);
}

Food::Food(double _hunger, double _hydration) {
    hunger = _hunger;
    hydration = _hydration;
}

Food::~Food() {}

Medication::Medication(double _health, double _sanity) {
    health = _health;
    sanity = _sanity;
}

Medication::~Medication() {}