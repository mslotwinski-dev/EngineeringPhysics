#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void Update(const T& car, double & speed, double & acceleration);

class Part {
    std::string name; 
    double acceleration;
    double topSpeed;

    public:
    Part(std::string = "Silnik", double = 4, double = 40);
    ~Part() {}

    inline bool operator == (Part a) { return name == a.name; }

    inline std::string GetName() { return this->name;}
    inline double GetAcceleration() { return this->acceleration;}
    inline double GetTopSpeed() { return this->topSpeed;}

    void Print();

};

class Vehicle {
    protected:
    
    std::string name;
    double acceleration;
    double topSpeed;

    public:
    Vehicle(std::string = "abc", double = 1, double = 50);
    virtual ~Vehicle() {}
    
    virtual void Print() = 0;

};

class RaceCar : public Vehicle {
    std::vector<Part> parts;
    bool busted = false;
    double bounty = 100;

    public:
    RaceCar(std::string = "BMW", double = 1, double = 50);
    ~RaceCar() {}

    void operator + (Part a); 
    void operator - (Part a); 

    void Print();
    void PrintNoParts();

    inline bool IsBusted() { return busted; }
    inline bool TopSpeed() { return topSpeed; }
    inline void Happy() { bounty += 1000; }
    inline void Sad() { busted = true; }

    template <typename T>
    friend void Update(const T& car, double & speed, double & acceleration);
};

class PoliceCar : public Vehicle {
    std::vector<RaceCar*> bustedCars;

    public:
    PoliceCar(std::string = "Cross", double = 3, double = 70);
    ~PoliceCar() {}

    void Chase(RaceCar&);

    void Print();

    template <typename T>
    friend void Update(const T& car, double & speed, double & acceleration);
};