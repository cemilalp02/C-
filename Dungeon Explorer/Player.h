#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    int x, y;
    int health;
    int attack;
    int defense;

    Player();

    void move(char direction, char map[10][10]);
    void fight(class Monster& m);
};

#endif
