#ifndef PLAYER_H
#define PLAYER_H


class Player {
    int x;
    int y;

    public:
        Player(int x, int y);
        int getX() const {return this->x;};
        int getY() const {return this->y;};
        void move(int x, int y);
};


#endif