#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "Player.h"
#include "Monster.h"

const int MAP_ROWS = 10;
const int MAP_COLS = 10;

extern char map[MAP_ROWS][MAP_COLS];

void loadMapFromFile(const std::string& filename, char map[MAP_ROWS][MAP_COLS]);
void drawMap(const Player& player, const std::vector<Monster>& monsters);

#endif
