#include "player.h"

Player::Player(int x, int y) : 
    
    x{x}, 
    y{y} {}

Player::Player() : 
    
    x{0}, 
    y{0} {}

void Player::move(int x, int y) {
    
    this->x = x;
    this->y = y;
}
