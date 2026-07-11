#include "map.h"
#include "player.h"

Map::Map() : tiles{

    "##########",
    "#........#",
    "#........#",
    "#.......X#",
    "##########"
    
} {}

void Map::draw(const Player& player, const std::vector<Monster>& monsters) const {

    for (int y{0}; y < tiles.size(); ++y) {
        for (int x{0}; x < tiles.at(y).size(); ++x) {
            if (x == player.getX() && y == player.getY())
                std::cout << '@';
            else if (isMonster(x, y, monsters))
                std::cout << 'M';
            else
                std::cout << tiles.at(y).at(x);
        }
        std::cout << '\n';
    }
}

bool Map::isGoal(int x, int y) const {

    if (tiles.at(y).at(x) == 'X')
        return true;
    return false;
}

bool Map::isMonster(int x, int y, const std::vector<Monster>& monsters) const {

    for (const auto& m : monsters) {
        if (x == m.getX() && y == m.getY())
            return true;
    }
    return false;
}

bool Map::isWall (int x, int y) const {

    if (tiles.at(y).at(x) == '#')
        return true;
    return false;
}