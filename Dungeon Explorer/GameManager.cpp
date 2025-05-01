#include "GameManager.h"
#include "Map.h"
#include "Item.h"
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cctype>

using namespace std;

extern char map[10][10];
vector<Item> items;


void battleLoop(Player& player, Monster& monster) {
    while (player.health > 0 && monster.health > 0) {
        cout << "\nThe war has begun!\n";

        player.fight(monster);

        if (monster.health <= 0) {
            cout << " Monster defeated!\n";
            break;
        }

        int monsterDamage = max(0, monster.attack - player.defense);
        player.health -= monsterDamage;
        cout << "Monster attacked back and damaged " << monsterDamage << " to you!\n";

        cout << "Your HP: " << player.health << " | Enemy HP: " << monster.health << "\n";

        if (player.health <= 0) {
            cout << "\n You are dead. Game over.\n";
            exit(0);
        }

        cout << "Press Enter to continue the battle...\n";
        cin.ignore();
    }
}

void setupLevel(int level, Player& player, vector<Monster>& monsters) {
    items.clear();
    string filename = "levels/level" + to_string(level) + ".txt";
    loadMapFromFile(filename, map);

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 10; ++x) {
            switch (map[y][x]) {
                case '@':
                    player.x = x;
                    player.y = y;
                    map[y][x] = '.';
                    break;
                case 'M':
                    monsters.push_back(Monster(x, y));
                    map[y][x] = '.';
                    break;
                case '!':
                    items.push_back(Item(x, y, ItemType::Potion, 20));
                    map[y][x] = '.';
                    break;
                case ')':
                    items.push_back(Item(x, y, ItemType::Weapon, 5));
                    map[y][x] = '.';
                    break;
                case ']':
                    items.push_back(Item(x, y, ItemType::Armor, 3));
                    map[y][x] = '.';
                    break;
            }
        }
    }
}

void gameLoop(Player& player, vector<Monster>& monsters, int& level) {
    while (true) {
        drawMap(player, monsters);

        string line;
        cout << "\nMovement (W,A,S,D): ";
        getline(cin >> ws, line);
        if (line.empty()) continue;

        char input = tolower(line[0]);
        if (input != 'w' && input != 'a' && input != 's' && input != 'd') {
            cout << "Invalid input! Please use W, A, S, or D.\n";
            continue;
        }

        player.move(input, map);
        checkItemPickup(player, items, map);


        for (auto& m : monsters) {
            m.moveTowardPlayer(player, map);
        }


        for (auto it = monsters.begin(); it != monsters.end(); ) {
            if (player.x == it->x && player.y == it->y) {
                battleLoop(player, *it);

                if (it->health <= 0) {
                    it = monsters.erase(it);
                } else {
                    ++it;
                }

                drawMap(player, monsters);
                break;
            } else {
                ++it;
            }
        }

        if (map[player.y][player.x] == 'X') {
            cout << "\n Level " << level << " completed!\n";
            level++;
            saveGame(level, player, monsters);

            if (level > 10) {
                cout << " CONGRATULATIONS! You won the game!\n";
                return;
            }

            monsters.clear();
            setupLevel(level, player, monsters);
            continue;
        }

        if (player.health <= 0) {
            cout << "\nYou are dead. Game over.\n";
            return;
        }

        drawMap(player, monsters);
    }
}

void saveGame(int level, const Player& player, const vector<Monster>& monsters) {
    ofstream file("save.txt");
    if (!file) return;
    file << level << "\n";
    file << player.x << " " << player.y << " " << player.health << " "
         << player.attack << " " << player.defense << "\n";
    file << monsters.size() << "\n";
    for (const auto& m : monsters) {
        file << m.x << " " << m.y << " " << m.health << "\n";
    }
    cout << "Game saved (Level " << level << ").\n";
}

bool loadGame(int& level, Player& player, vector<Monster>& monsters) {
    ifstream file("save.txt");
    if (!file) return false;

    file >> level;
    file >> player.x >> player.y >> player.health >> player.attack >> player.defense;

    int count;
    file >> count;
    monsters.clear();
    for (int i = 0; i < count; ++i) {
        int x, y, hp;
        file >> x >> y >> hp;
        Monster m(x, y);
        m.health = hp;
        monsters.push_back(m);
    }

    cout << " Save loaded (Level " << level << ").\n";
    return true;
}

void deleteSaveFile() {
    remove("save.txt");
    cout << "The save file has been deleted.\n";
}
