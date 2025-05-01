#ifndef ITEM_H
#define ITEM_H

#include <vector>

enum class ItemType { Potion, Weapon, Armor };

struct Item {
    int x, y;
    ItemType type;
    int value;

    Item(int x_, int y_, ItemType type_, int value_)
        : x(x_), y(y_), type(type_), value(value_) {}
};


void checkItemPickup(class Player& player, std::vector<Item>& items, char map[10][10]);

#endif
