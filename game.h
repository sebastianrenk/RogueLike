#pragma once
#include "player.h"
#include "map.h"

class Game {

    Map map;
    Player player;
    bool running;

    public: 
        
        Game(bool running = true);
        void handleInput(char c);
        void run();
};