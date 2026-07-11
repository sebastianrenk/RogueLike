#include <iostream>
#include <string>
#include <vector>
#include "player.h"

#ifndef MAP_H
#define MAP_H

class Map{

    std::vector<std::string> tiles;

    public:
    
        Map();
        void draw(const Player& player) const;
        bool isWall (int x, int y);
};





#endif