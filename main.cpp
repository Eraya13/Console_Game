#include <iostream>
#include "Map.h"
#include "Game.h"
#include "02_Entity/Weapon.h"
#include "02_Entity/Item.h"
#include "02_Entity/Potion.h"
#include "02_Entity/Armor.h"
#include "00_Players_Classes/Inventory.h"


int main() {
    // Get the current working directory
    //std::filesystem::path currentPath = std::filesystem::current_path();
    //std::cout << "Current working directory: " << currentPath << std::endl;
    //Map* mapa = new Map("LocationsNames.txt");
    
    int health=50;
    Inventory* inventory = new Inventory();
    inventory->addItem(new Potion("Health Potion"));
    inventory->addItem(new Weapon("Silver katana", 40));
    inventory->addItem(new Armor("Welvet gear", 40));
    View::initInventory(inventory);
    // budeme chtít přistoupit inventář
    ConsoleManager::displayInventoryMenu();
    ConsoleManager::cursorNavigation(4, 3);
    ConsoleManager::executeInventoryMenuOption();



    //Game* hra = new Game();
    //hra->setGameElements();
    //hra->gameLoop();
    system("cls");
    
    delete inventory;
    //delete mapa;
    return 0;
}
