#include <vector>
#include <iostream>
#include "map.h"
#include "player.h"

int main() {

    Map map;
    Player player(2, 3);
    map.draw(player);
    bool running{true};
    while (running) {
        char input;
        std::cin >> input;
        switch(input) {
            case 'w':
                player.move(0, -1);
                break;
            case 'a':
                player.move(-1, 0);
                break;
            case 's':
                player.move(0, 1);
                break;
            case 'd':
                player.move(1, 0);
                break;
        }
        if (input == 'e')
            running = false;
        for (int i{0}; i < 50; ++i)
            std::cout << '\n';
        map.draw(player);

    }
    
    return 0;
}