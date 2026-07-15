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
        "#.....M.X#",
        "#...M....#",
        "#.@......#",
        "##########"
    };

    std::vector<std::string> layout3{ 
    
        "##########",
        "#.@...M..#",
        "#...#...X#",
        "#.M...#..#",
        "##########"
    };

    std::vector<std::string> layout4{ 
    
        "##########",
        "#.@....M.#",
        "#.####...#",
        "#..M....X#",
        "##########"
    };

    std::vector<std::string> layout5{ 
    
        "##########",
        "#.@...M..#",
        "#....M...#",
        "#.M.....X#",
        "##########"
    };

    std::vector<std::string> layout6{ 
    
        "##########",
        "#X.#.....#",
        "#..#..#..#",
        "#.M...#.@#",
        "##########"
    };

    std::vector<std::string> layout7{ 
    
        "##########",
        "#..####..#",
        "#........#",
        "#XM..@.M.#",
        "##########"
    };

    std::vector<std::string> layout8{ 
    
        "##########",
        "#.######.#",
        "#XM.....@#",
        "#..#.#.#.#",
        "##########"
    };

    std::vector<std::string> layout9{ 
    
        "##########",
        "##...#...#",
        "#X#.#.M..#",
        "#..M...#@#",
        "##########"
    };

    std::vector<std::string> layout10{ 
    
        "##########",
        "#@..#X...#",
        "#...###..#",
        "#M......M#",
        "##########"
    };

    std::vector<Level> levels;
    Level level1{layout};
    Level level2{layout2};
    Level level3{layout3};
    Level level4{layout4};
    Level level5{layout5};
    Level level6{layout6};
    Level level7{layout7};
    Level level8{layout8};
    Level level9{layout9};
    Level level10{layout10};
    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(level3);
    levels.push_back(level4);
    levels.push_back(level5);
    levels.push_back(level6);
    levels.push_back(level7);
    levels.push_back(level8);
    levels.push_back(level9);
    levels.push_back(level10);

    Game game{levels};
    game.run();

    return 0;
}