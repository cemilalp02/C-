#ifndef MONSTER_H
#define MONSTER_H

class Player;

class Monster {
public:
    int x, y;
    int health;
    int attack;
    int defense;

    Monster(int startX, int startY);

    void moveTowardPlayer(const Player& player, char map[10][10]);
};

#endif
