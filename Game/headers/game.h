#include <iostream>
#include "character.h"
#include "map.h"

class Game {

public:

    Game(Character& chr, Map& map): chr_(chr), map_(map) {
        chr_ = chr;
        map_ = map;
    }

    void Check() {
        std::cout << chr_ << std::endl << map_ << std::endl;
    }

    void GameMap() {
        map_.GetMap().clear();
        map_.GenerateMap();
        map_.GetMap()[chr_.GetPos()] = chr_.GetModel();
        std::cout << map_ << std::endl;
    }

    void Exploration(std::istream& is) {
        
        char action = '0';

        std::cout << map_;

        while (is >> action) {

            this->GameMap();
            
            switch (action) {
                case 'a':
                chr_.Move(-1);
                break;

                case 'd':
                chr_.Move(1);
                break;
            }
        }
    }

private:
    Character chr_;
    Map map_;
};