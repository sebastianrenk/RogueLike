#pragma once

class Monster{

    int x;
    int y;

    public:
        
        Monster(int x, int y);
        int getX() const {return x;}
        int getY() const {return y;}
        void set(int x, int y);
};