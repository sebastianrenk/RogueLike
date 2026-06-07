#include <vector>
#include <iostream>
#include "map.h"
#include "player.h"

int main() {

    Map map;
    Player player(2, 3);
    map.draw(player);
    
    return 0;
}