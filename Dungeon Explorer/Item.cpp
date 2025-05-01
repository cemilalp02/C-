#include "Item.h"
#include "Player.h"
#include <iostream>

void checkItemPickup(Player& player, std::vector<Item>& items, char map[10][10]) {
    for (auto it = items.begin(); it != items.end(); ) {
        if (player.x == it->x && player.y == it->y) {
            switch (it->type) {
                case ItemType::Potion:
                    player.health += it->value;
                std::cout << " You got the potion! Life +" << it->value << "\n";
                break;
                case ItemType::Weapon:
                    player.attack += it->value;
                std::cout << " You found a weapon! Attack +" << it->value << "\n";
                break;
                case ItemType::Armor:
                    player.defense += it->value;
                std::cout << "You're wearing armor! Defense +" << it->value << "\n";
                break;
            }

            map[it->y][it->x] = '.';
            it = items.erase(it);
        } else {
            ++it;
        }
    }
}
