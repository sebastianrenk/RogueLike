#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "monster.h"

#ifndef MAP_H
#define MAP_H

class Map{

    std::vector<std::string> tiles;

    public:
    
        Map();
        void draw(const Player& player, const std::vector<Monster>& monsters) const;
        bool isMonster(int x, int y, const std::vector<Monster>& monsters) const;
        bool isWall (int x, int y) const;
};





#endif