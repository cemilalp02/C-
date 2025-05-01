#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include <vector>

void setupLevel(int level, Player& player, std::vector<Monster>& monsters);
void gameLoop(Player& player, std::vector<Monster>& monsters, int& level);
void saveGame(int level, const Player& player, const std::vector<Monster>& monsters);
bool loadGame(int& level, Player& player, std::vector<Monster>& monsters);
void deleteSaveFile();

#endif
