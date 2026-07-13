#pragma once

#include "monster.h"
#include "player.h"
#include "map.h"
#include "level.h"

class Game {
    
    Level level;
    Map map;
    Player player;
    std::vector<Monster> monsters;
    bool running;

    public: 
        
        Game(Level& level, bool running = true);
        void handleInput(char c);
        void run();
        bool gotHit() const;
        bool reachedGoal() const;
};