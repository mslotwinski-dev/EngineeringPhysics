#include "1.hpp"

int main() {
    Game Witcher("Witcher 3", RPG, 100);
    Game LOL("League of Legends", MOBA, 1200);
    Game Minecraft("Minecraft", CHILL, 14200);

    std::vector<Game> db ({Witcher, LOL, Minecraft});

    printLibrary(db);
    return 0;
}
