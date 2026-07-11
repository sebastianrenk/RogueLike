#include "game.h"

Game::Game(bool running) :

    running{running} {}


void Game::handleInput(char c) {

    int targetX{player.getX()};
    int targetY{player.getY()};

    switch(c) {
            case 'w':
                targetX += 0;
                targetY += -1;
                break;
            case 'a':
                targetX += -1;
                targetY += 0;
                break;
            case 's':
                targetX += 0;
                targetY += 1;
                break;
            case 'd':
                targetX += 1;
                targetY += 0;
                break;
            case 'e':
                running = false;
                break;
        }

    if (!map.isWall(targetX, targetY))
        player.move(targetX, targetY);
}

void Game::run() {

    while (running) {

        map.draw(player);
        char input;
        std::cin >> input;
        handleInput(input);
        for (int i{0}; i < 50; ++i)
            std::cout << '\n';
    }
}