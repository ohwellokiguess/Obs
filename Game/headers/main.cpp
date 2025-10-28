#include "game.h"

int main() {

    Character a{100, 10, 5, '1'};
    Map map{};

    Game game{a, map};
    game.Exploration(std::cin);

}