#include "View.h"

void View::howToSelect() {
    std::cout << "\t\t\t~Press [ENTER] to make selection";
}


void View::inGameMenu_m () {
    std::cout << "--------------****In Game Menu****---------------\n\n"
              << "\t\tPersonal Stats\n"
              << "\t\tInventory\n"
              << "\t\tExit Menu\n"
              << "\t\tLeave Game\n\n";
    howToSelect();
}

void View::playerStats() {
    std::cout << "-----------**Personal Stats**-----------" << "\n\n";
            /*<< "\t\t Name:\t" << m_player->getName() << "\n"
            << "\t\t Health:\t" << m_player->getHealth() << "\n"
            << "\t\t Attack damage:\t" << m_player->getAttack() << "\n"
            << "\t\t Defense:\t" << /*defense <<
            "\n\n"*/
    std::cout << "Equipped armor:\t" << /*name armor <<*/ "\t\t-------**Experience**------"
              << "--\tDetails:\n"
              << "\t\tBonus defense: \n" << "\t\tLevel" // Level:
              << "\t\tDescription:" << "\n\n";  // Total XP: 40 (456 XP to next level)
    std::cout << "Equipped Weapon:\t" /*name weapon <<*/
              << "--\tDetails:\n"
              << "\t\tBonus attack: \n"
              << "\t\tDescription:" << "\n\n";;
    std::cout << "\t\t\t~Press [any key] to continue";
}

void View::Inventory_m(int totalPotions) {
    std::cout << "-----------**Inventory**-----------" << "\n\n"
              /*"Total Coins"*/
              << "\tHP potions: " << "\t\t" << totalPotions << "\n\n"
              << "\tDrink potion" << "\n"
              << "\tDisplay all items" << "\n"
              << "\tLeave Inventory" << "\n\n";
    howToSelect();
}

void View::listInventoryItems(std::vector<Item*> items) {
    std::cout << "---------------------------------------**Inventory**--------------------------------------" << "\n";
    std::cout << "\tType\t\t|\t\tName\t\t\t|\tItem Bonus\n"
              << "------------------------------------------------------------------------------------------\n";
    for (Item* item : items) {
        item->printBriefInfo();
    }
    std::cout << "  Leave Inventory\n\n\t\t\t";
    howToSelect();
}

void View::displayItem(Item* item) {
    system("cls");
    std::cout << "-----------**Item details**-----------" << "\n\n"
              << "\t" << item->getName() << "\n"
              << "\t" << item->getCategory();

    // dynamic cast special vlastnosti
    if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
        std::cout << "\t+" << weapon->getAttackBonus() << " damage\n\n";
        toEquipOption(weapon);
    }
    else if (Potion* potion = dynamic_cast<Potion*>(item)) {
        std::cout << "\n\tThis potion restores " << potion->getHealthBonus() << " health points on use"
                  << "\n\n\tDrink potion";
    }
    else if (Armor* armor = dynamic_cast<Armor*>(item)) {
        std::cout << "\t+" << armor->getDefenseBonus() << " defense\n\n";
        toEquipOption(armor);
    }
    else {
        std::cout << "\nDynamic cast of Item* Father failed" << std::endl;
    }
    displayItem_m();
    system("pause");
}

void View::displayItem_m() {
    std::cout << "\tDiscard item" << "\n"
              << "\tBack to inventory" << "\n\n";
    howToSelect();
}

void View::toEquipOption(Weapon* weapon) {
    if (weapon->isEquipped()) {
        std::cout << "\tUnequip" << "\n";
    }
    else {
        std::cout << "\tEquip" << "\n";
    }
}

void View::toEquipOption(Armor* armor) {
    if (armor->isEquipped()) {
        std::cout << "\tUnequip" << "\n";
    }
    else {
        std::cout << "\tEquip" << "\n";
    }
}
