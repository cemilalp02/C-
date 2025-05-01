#include <iostream>
#include <cctype>
#include "GameManager.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

void Menu() {
   int choice;
   Player player;
   vector<Monster> monsters;
   int level = 1;

   while (true) {
      cout << "\n1. Start New Game\n";
      cout << "2. Load The Game\n";
      cout << "3. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
         case 1:
            deleteSaveFile();
         setupLevel(level, player, monsters);
         gameLoop(player, monsters, level);
         break;

         case 2:
            if (!loadGame(level, player, monsters)) {
               cout << "No save file found.\n";
            } else {
               setupLevel(level, player, monsters);
               gameLoop(player, monsters, level);
            }
         break;

         case 3:
            cout << "Exiting the game.\n";
         return;

         default:
            cout << "Invalid choice. Try again.\n";
      }
   }
}

int main() {
   Menu();
   return 0;
}
