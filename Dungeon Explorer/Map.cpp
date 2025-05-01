#include "Map.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <fstream>

char map[MAP_ROWS][MAP_COLS];

void loadMapFromFile(const std::string& filename, char map[MAP_ROWS][MAP_COLS]) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "Could not open map file: " << filename << "\n";
    return;
  }

  for (int y = 0; y < MAP_ROWS; ++y) {
    for (int x = 0; x < MAP_COLS; ++x) {
      file >> map[y][x];
    }
  }
}

void drawMap(const Player& player, const std::vector<Monster>& monsters) {

    for (int i = 0; i < 30; ++i) std::cout << "\n";

    for (int y = 0; y < MAP_ROWS; ++y) {
        for (int x = 0; x < MAP_COLS; ++x) {
            bool drawn = false;


            for (const auto& m : monsters) {
                if (m.x == x && m.y == y && player.x == x && player.y == y) {
                    std::cout << '!';
                    drawn = true;
                    break;
                }
            }


            if (!drawn && player.x == x && player.y == y) {
                std::cout << '@';
                drawn = true;
            }


            if (!drawn) {
                for (const auto& m : monsters) {
                    if (m.x == x && m.y == y) {
                        std::cout << 'M';
                        drawn = true;
                        break;
                    }
                }
            }

            if (!drawn) {
                std::cout << map[y][x];
            }
        }
        std::cout << "\n";
    }

    std::cout << "\nHP: " << player.health
              << " | Atk: " << player.attack
              << " | Def: " << player.defense << "\n";
}
