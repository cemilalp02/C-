#include "Monster.h"
#include "Player.h"
#include <cstdlib>
#include <cmath>

Monster::Monster(int startX, int startY) {
    x = startX;
    y = startY;
    health = 50;
    attack = 15;
    defense = 5;
}


void Monster::moveTowardPlayer(const Player& player, char map[10][10]) {
    int dx = player.x - x;
    int dy = player.y - y;

    int newX = x;
    int newY = y;


    if (std::abs(dx) > std::abs(dy)) {
        newX += (dx > 0) ? 1 : -1;
    } else if (dy != 0) {
        newY += (dy > 0) ? 1 : -1;
    }


    if (map[newY][newX] != '#') {
        x = newX;
        y = newY;
    }
}
