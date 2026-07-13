#pragma once

#include <string>
#include <vector>
#include "player.h"
#include "map.h"
#include "monster.h"

class Level{

    std::vector<std::string> layout;
    int startX;
    int startY;
    std::vector<Monster> monsters;

    public:

        Level(std::vector<std::string>& layout);
        int getStartX() const {return startX;}
        int getStartY() const {return startY;}
        const std::vector<Monster> getMonsters() const {return monsters;}
        const std::vector<std::string>& getLayout() const {return layout;}
};