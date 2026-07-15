#pragma once

#include <random>
#include "monster.h"
#include "player.h"
#include "map.h"
#include "level.h"

class Game {
    
    std::vector<Level> levels;
    int currentLevel;
    Map map;
    Player player;
    std::vector<Monster> monsters;
    bool running;
    int lives;

    public: 
        
        Game(std::vector<Level> levels, int currentLevel = 0, bool running = true, int lives = 3);
        void loadLevel(int index);
        void handleInput(char c);
        void run();
        bool gotHit() const;
        bool reachedGoal() const;
        void moveMonsters();
        int getLives() const {return lives;}
};