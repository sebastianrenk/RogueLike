#include "player.h"

Player::Player(int x, int y) : x{x}, y{y} {}

void Player::move(int x, int y) {
    this->x += x;
    this->y += y;
}