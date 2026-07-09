#include "monster.h"

Monster::Monster(int x, int y) : x{x}, y{y} {}

void Monster::set(int x, int y) {

    this->x = x;
    this->y = y;
}