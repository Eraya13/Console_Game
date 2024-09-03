#include "View.h"

// Inicializace statického ukazatele
Player* View::m_player = nullptr;
Inventory* View::m_inventory = nullptr;

void View::init(Player* player) {
    m_player = player;
}

void View::initInventory(Inventory* inventory) {
    m_inventory = inventory;
}

void View::inGameMenu_m () {
    std::cout << "--------------****In Game Menu****---------------\n\n"
              << "\t\tPersonal Stats\n"
              << "\t\tInventory\n"
              << "\t\tExit Menu\n"
              << "\t\tLeave Game\n\n"
              << "\t\t\t\t~Press [ENTER] to make selection";
}

void View::playerStats() {
    std::cout << "-----------**Personal Stats**-----------" << "\n\n"
            << "\t\t Name:\t" << m_player->getName() << "\n"
            << "\t\t Health:\t" << m_player->getHealth() << "\n"
            << "\t\t Attack damage:\t" << m_player->getAttack() << "\n"
            << "\t\t Defense:\t" << /*defense <<*/ "\n\n";
    std::cout << "Equipped armor:\t" << /*name armor <<*/ "\t\t-------**Experience**------"
              << "--\tDetails:\n"
              << "\t\tBonus defense: \n" << "\t\tLevel" // Level:
              << "\t\tDescription:" << "\n\n";  // Total XP: 40 (456 XP to next level)
    std::cout << "Equipped Weapon:\t" /*name weapon <<*/
              << "--\tDetails:\n"
              << "\t\tBonus attack: \n"
              << "\t\tDescription:" << "\n\n";;
    std::cout << "t\t\t~Press [any key] to continue";
}

void View::Inventory_m() {
    std::cout << "-----------**Inventory**-----------" << "\n\n"
              /*"Total Coins"*/
              << "\tHP potions: " << "\t\t" << m_inventory->getNumberOfPotions() << "\n\n"
              << "\tDrink potion" << "\n"
              << "\tDisplay all items" << "\n"
              << "\tLeave Inventory" << "\n\n"
              << "\t\t\t~Press [ENTER] to make selection";
}

void View::listInventoryItems() {
    std::vector<Item*> itemList = m_inventory->getItemList();
    int totalNumberItems = 0;
    std::cout << "\tType\t\t|\tName\t\t\t|\tItem Bonus\n"
              << "----------------------------------------------------------------------------------------------\n";
    for (Item* item : itemList) {
        item->printBriefInfo();
        totalNumberItems++;
    }
    std::cout << "\n\nTotal number of items: " << totalNumberItems << "\n\n";
}

