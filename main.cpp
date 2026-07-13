#include <vector>
#include <iostream>
#include "game.h"
#include "map.h"
#include "player.h"
#include "level.h"

int main() {

    std::vector<std::string> layout{ 
    
        "##########",
        "#.@......#",
        "#...X....#",
        "#.M...M..#",
        "##########"
    };

    Level level1{layout};
    Game game{level1};
    game.run();

    return 0;
}