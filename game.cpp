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

bool Game::gotHit() {

    for (const auto& m : monsters) {
        if (player.getX() == m.getX() && player.getY() == m.getY())
            return true;
    }
    return false;
}

void Game::run() {

    while (running) {

        Monster m1{4, 1};
        monsters.push_back(m1);
        map.draw(player, monsters);
        char input;
        std::cin >> input;
        handleInput(input);
        if (gotHit()) {
            std::cout << "==========YOU DIED==========\n";
            running = false;
        } else {
            for (int i{0}; i < 50; ++i)
                std::cout << '\n';
        }
    }
}