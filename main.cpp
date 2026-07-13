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

    std::vector<std::string> layout2{ 
    
        "##########",
        "#.@...M..#",
        "#....M...#",
        "#.M.....X#",
        "##########"
    };

    std::vector<std::string> layout3{ 
    
        "##########",
        "#.@....M.#",
        "#.####...#",
        "#..M....X#",
        "##########"
    };

    /*std::vector<Level> levels;
    Level level1{layout};
    Level level2{layout2};
    Level level3{layout3};
    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(level3);*/
    
    Level level1{layout};
    Game game{level1};
    std::cout << "==========Level 1==========\n";
    game.run();
    if (game.reachedGoal()) {
        Level level2{layout2};
        Game game{level2};
        std::cout << "==========Level 2==========\n";
        game.run();
        if (game.reachedGoal()) {
            Level level3{layout3};
            Game game{level3};
            std::cout << "==========Level 3==========\n";
            game.run();
        }
    }

    return 0;
}