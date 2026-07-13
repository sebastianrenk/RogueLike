#pragma once
#include "monster.h"
#include "player.h"
#include "map.h"

class Game {

    Map map;
    Player player;
    std::vector<Monster> monsters;
    bool running;

    public: 
        
        Game(Map map, bool running = true);
        void handleInput(char c);
        void run();
        bool gotHit() const;
        bool reachedGoal() const;
};