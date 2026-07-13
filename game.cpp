#include "game.h"

Game::Game(std::vector<Level> levels, int currentLevel, bool running) :

    levels{levels},
    currentLevel{currentLevel},
    running{running} {

        loadLevel(0);
    }


void Game::loadLevel(int index) {

    map = Map{levels.at(index).getLayout()};
    player = Player{levels.at(index).getStartX(), levels.at(index).getStartY()};
    monsters = std::vector<Monster>{levels.at(index).getMonsters()};
}

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

bool Game::gotHit() const{

    for (const auto& m : monsters) {
        if (player.getX() == m.getX() && player.getY() == m.getY())
            return true;
    }
    return false;
}

bool Game::reachedGoal() const {

    if (map.isGoal(player.getX(), player.getY()))
        return true;
    return false;
}

void Game::run() {

    while (running) {

        std::cout << "========== Level " << currentLevel + 1 << " ==========\n";
        map.draw(player, monsters);
        char input;
        std::cin >> input;
        handleInput(input);
        
        if (gotHit()) {
            std::cout << "========== YOU DIED ==========\n";
            running = false;
        } else if (reachedGoal()) {
            std::cout << "========== YOU WON ==========\n";
            if (++currentLevel < levels.size()) {
                loadLevel(currentLevel);
            } else {
                std::cout << "CONGRATULATIONS, YOU COMPLETED THE GAME\n";
                running = false;
            }
        } else {
            for (int i{0}; i < 50; ++i)
                std::cout << '\n';
        }
    }
}