#include "1.hpp"

Game::Game(std::string _name, types _type, int _time) {
    name = _name;
    type = _type;
    time = _time; 
}

void Game::Print() {
    std::cout<<"Name: "<<name<<", Type: "<<arr[type]<<", Time: "<<time<<std::endl;
}

void printLibrary(std::vector<Game> db) {

    auto print = [](Game& n) { n.Print(); };

    std::for_each(db.begin(), db.end(), print);
}