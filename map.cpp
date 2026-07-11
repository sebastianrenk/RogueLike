#include "map.h"
#include "player.h"

Map::Map() : tiles{

    "##########",
    "#........#",
    "#........#",
    "#........#",
    "##########"
    
} {}

void Map::draw(const Player& player) const {

    for (int y{0}; y < tiles.size(); ++y) {
        for (int x{0}; x < tiles.at(y).size(); ++x) {
            if (x == player.getX() && y == player.getY())
                std::cout << "@";
            else
                std::cout << tiles.at(y).at(x);
        }
        std::cout << '\n';
    }
}

bool Map::isWall (int x, int y) {

    if (tiles.at(y).at(x) == '#')
        return true;
    return false;
}