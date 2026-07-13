#pragma once

class Player {
    
    int x;
    int y;

    public:

        Player(int x, int y);
        Player();
        int getX() const {return x;};
        int getY() const {return y;};
        void move(int x, int y);
};