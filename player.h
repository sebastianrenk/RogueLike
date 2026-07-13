#ifndef PLAYER_H
#define PLAYER_H


class Player {
    
    int x;
    int y;

    public:

        Player(int x, int y);
        int getX() const {return x;};
        int getY() const {return y;};
        void move(int x, int y);
};

#endif