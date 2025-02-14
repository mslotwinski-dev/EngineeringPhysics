#include <algorithm>
#include <iostream>
#include <vector>

enum types {RPG, MOBA, CHILL};

class Game {
    std::string name;
    types type;
    int time;

    std::string arr[3] = {"RPG", "MOBA", "CHILL"};
    
    public:
        Game(std::string _name, types _type, int _time);
        void Print();
};

void printLibrary(std::vector<Game> db);