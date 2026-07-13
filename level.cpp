#include "level.h"

Level::Level(std::vector<std::string>& layout) : 

    layout{layout} {

        for (int y{0}; y < layout.size(); ++y) {
            for (int x{0}; x < layout.at(y).size(); ++x) {
                if (layout.at(y).at(x) == '@') {
                    startX = x;
                    startY = y;
                    this->layout.at(y).at(x) = '.';
                } else if (layout.at(y).at(x) == 'M') {
                    Monster m{x, y};
                    monsters.push_back(m);
                    this->layout.at(y).at(x) = '.';
                }
            }
        }
    }
