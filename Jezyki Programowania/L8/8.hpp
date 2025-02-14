#include <iostream>
#include <algorithm>
#include <vector>

class Present {
    std::string name;
    double weight;

    public:
    Present(std::string = "Wegiel", double = 1);
    ~Present() {}

    double _weight() const { return weight; }

    void Print();

    bool operator == (const Present) const;
};

class Tree {
    const int capacity;
    std::vector<Present> presents;

    public:
    Tree(double capacity = 5) : capacity(capacity) {};
    ~Tree() {}

    void Print();
    bool HasPresents() { return presents.size() > 0; }
    Present GrabPresent() { return presents[0]; }

    void operator += (Present);
    Present operator -= (Present);
};

class Grinch {
    double energy;
    std::vector<Present> bag;

    public:
    Grinch(double _energy = 8) { energy = _energy; };
    ~Grinch() {};

    void Print();
    void StealChristmas(Tree&);
};