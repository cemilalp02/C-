#include "Player.h"
#include "Monster.h"
#include <iostream>

Player::Player() {
  x = 0;
  y = 0;
  health = 100;
  attack=13;
  defense=10;
}
void Player::move(char direction, char map[10][10]) {
  int newX = x;
  int newY = y;

  switch (direction) {
    case 'w': newY--; break;
    case 's': newY++; break;
    case 'a': newX--; break;
    case 'd': newX++; break;
    default:
      std::cout << "Invalid movement key!\n";
    return;
  }

  if (map[newY][newX] == '#') {
    std::cout << "You hit the wall!\n";
  } else {
    x = newX;
    y = newY;
  }
}

void Player::fight(Monster& m) {
  std::cout << "\n The war has begun!\n";
  int damageToMonster = std::max(0, attack - m.defense);
  m.health -= damageToMonster;
  std::cout << "player damaged " << damageToMonster << " to monster.\n";

  if (m.health > 0) {

    int damageToPlayer = std::max(0, m.attack - defense);
    health -= damageToPlayer;
    std::cout << "Monster damaged " << damageToPlayer << "to you!\n";
  }
}