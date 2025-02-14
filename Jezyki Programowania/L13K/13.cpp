#include "13.hpp"

Part::Part(std::string name, double a, double v) {
    this->name = name;
    this->acceleration = a;
    this->topSpeed = v;
}

void Part::Print() {
    std::cout<<name<<": Przyspieszenie +"<<acceleration<<"m/s2, Predkosc: +"<<topSpeed <<"m/s" <<std::endl;
}

Vehicle::Vehicle(std::string name, double a, double v) {
    this->name = name;
    this->acceleration = a;
    this->topSpeed = v;
}

RaceCar::RaceCar(std::string name, double a, double v) {
    this->name = name;
    this->acceleration = a;
    this->topSpeed = v;
}

void RaceCar::operator + (Part a) {
    auto item = std::find(parts.begin(), parts.end(), a);

    if (item != parts.end()) {
        std::cout<<"Taki przedmiot juz istnieje "<<a.GetName()<<std::endl;
    } else {
        parts.push_back(a);
        acceleration += a.GetAcceleration();
        topSpeed += a.GetTopSpeed();
    }
}

void RaceCar::operator - (Part a) {
    auto item = std::find(parts.begin(), parts.end(), a);

    if (item != parts.end()) {
        acceleration -= (*item).GetAcceleration();
        topSpeed -= (*item).GetTopSpeed();
        parts.erase(item);
    } else {
        std::cout<<"Nie znaleziono przedmiotu o nazwie "<<a.GetName()<<std::endl;
    }
}

void RaceCar::Print () {
    std::cout<<"Samochod "<<name<<" (Bounty "<<bounty<<") : Przyspieszenie "<<acceleration<<"m/s2, Predkosc: "<<topSpeed <<"m/s" <<std::endl;
    std::cout<<"Lista czesci:"<<std::endl;

    for (auto i : parts) {
        i.Print();
    }

    std::cout<<std::endl;
}

void RaceCar::PrintNoParts () {
    std::cout<<"Samochod "<<name<<" (Bounty "<<bounty<<") : Przyspieszenie "<<acceleration<<"m/s2, Predkosc: "<<topSpeed <<"m/s" <<std::endl;
}

PoliceCar::PoliceCar(std::string name, double a, double v) {
    this->name = name;
    this->acceleration = a;
    this->topSpeed = v;
}

template <typename T>
void Update(const T& car, double & speed, double & distance) {
    // t = 1
    if (speed < car.topSpeed) {
        distance += speed + car.acceleration / 2;
        speed += car.acceleration;
    } else {
        speed = car.topSpeed;
        distance += speed;
    }
}

void PoliceCar::Chase(RaceCar& c) {
    if (c.IsBusted()) {
        std::cout<<"Poscig nie ma sensu"<<std::endl;
    }

    double distance_car = 50;
    double distance_police = 0;

    double speed_car = 0.3*c.TopSpeed();
    double speed_police = 0;

    while (true) {
        Update(c, speed_car, distance_car);
        Update(*this, speed_police, distance_police);

        if (distance_car > distance_police + 1000) {
            c.Happy();
            break;
        }

        if (distance_car <= distance_police) {
            c.Sad();
            bustedCars.push_back(&c);
            break;
        }
    }

    std::cout << "Dlugosc poscigu: " << distance_police << std::endl;
}

void PoliceCar::Print () {
    std::cout<<"Policja "<<name<<" (Zlapanych samochodow "<<bustedCars.size()<<") : Przyspieszenie "<<acceleration<<"m/s2, Predkosc: "<<topSpeed <<"m/s" <<std::endl;
    std::cout<<"Lista czesci:"<<std::endl;

    for (auto i : bustedCars) {
        i->PrintNoParts();
    }

    std::cout<<std::endl;
}