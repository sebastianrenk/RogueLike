#include "game.h"

Game::Game(std::vector<Level> levels, int currentLevel, bool running, int lives) :

    levels{levels},
    currentLevel{currentLevel},
    running{running},
    lives{lives} {

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

void Game::moveMonsters() {

    for (auto& m : monsters) {
        int targetX{m.getX()};
        int targetY{m.getY()};

        int random{rand() % 4};

        switch(random) {
            case 0:
                targetX += 0;
                targetY += -1;
                break;
            case 1:
                targetX += -1;
                targetY += 0;
                break;
            case 2:
                targetX += 0;
                targetY += 1;
                break;
            case 3:
                targetX += 1;
                targetY += 0;
                break;
        }

    if (!map.isWall(targetX, targetY))
        m.move(targetX, targetY);
    }
}

void Game::run() {

    while (running) {

        std::cout << "========== Level " << currentLevel + 1 << " ==========\n";
        std::cout << "========== Health " << lives << " ==========\n\n";
        map.draw(player, monsters);
        char input;
        std::cin >> input;
        handleInput(input);
        moveMonsters();
        
        if (gotHit()) {
            if (--lives > 0) {
                for (int i{0}; i < 50; ++i)
                    std::cout << '\n';
                std::cout << "========== HEALTH DECREASED ==========\n\n";
                loadLevel(currentLevel);
            } 
            else {
                std::cout << "========== GAME OVER ==========\n";
                running = false;
            }
        } else if (reachedGoal()) {
            std::cout << "========== LEVEL COMPLETED ==========\n\n";
            if (++currentLevel < levels.size()) {
                loadLevel(currentLevel);
            } else {
                std::cout << "CONGRATULATIONS, YOU WON THE GAME\n";
                running = false;
            }
        } else {
            for (int i{0}; i < 50; ++i)
                std::cout << '\n';
        }
    }
}