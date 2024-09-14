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

void View::displayGameInstructions() {
    std::cout << "-----------**Game Instructions**-----------" << "\n\n";

    std::cout << "Movement:\n\n"
              << "\tUse W, A, S, D keys to move on the map." << "\n\n"
              <<  "\t *W* - UP" << "\t *A* - LEFT \n"
              <<  "\t *S* - DOWN" << "\t *D* - RIGHT \n\n";

    std::cout << "Control of game Menu:\n\n"
              << "\tPress [Tab] to display the Game Menu." << "\n"
              << "\tNavigate menu options with W, A, S, D keys." << "\n"
              << "\tConfirm selection with [Enter]." << "\n\n"
              << "\tExit the game by pressing [Esc]." << "\n\n";

    std::cout << "Game Menu Options:\n\n"
              << "\tView Personal Stats, Inventory, Leave menu and Quit Game" << "\n\n";

    std::cout << "Health and Game Over:\n\n"
              << "\tThe game will continue as long as you have at least 1 life." << "\n"
              << "\tIf you lose all your health, it's Game Over." << "\n\n";

    std::cout << "Starting Equipment:\n\n"
              << "\tYou start with basic armor and no weapon." << "\n\n";

   // std::cout << "\t\t\t~Press [any key] to continue" << std::endl;
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

void View::displayInventory_m(int totalPotions) {
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

void View::displayItemInfo(Item* item) {
    system("cls");
    std::cout << "-----------**Item details**-----------" << "\n\n"
              << "\t" << item->getName() << "\n"
              << "\t" << item->getCategory();

    // dynamic cast special vlastnosti
    if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
        std::cout << "\n\tThis weapon increases attack power by " << weapon->getAttackBonus()
                  << " points, enhancing the player's damage potential.\n\n";
    }
    else if (Potion* potion = dynamic_cast<Potion*>(item)) {
        std::cout << "\n\tThis potion restores " << potion->getHealthBonus()
                  << " health points on use.\n\n";
    }
    else if (Armor* armor = dynamic_cast<Armor*>(item)) {
        std::cout << "\n\tThis armor increases defense by " << armor->getDefenseBonus()
                  << " points, making the player more resilient to damage.\n\n";
    }
    else {
        std::cout << "\nDynamic cast of Item* (Father) failed" << std::endl;
    }
}

void View::displayItemActions(Item* item) {
    // dynamic cast special vlastnosti
    if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
        toEquipOption(weapon);
    }
    else if (Potion* potion = dynamic_cast<Potion*>(item)) {
    std::cout << "\tDrink potion\n";
    }
    else if (Armor* armor = dynamic_cast<Armor*>(item)) {
        toEquipOption(armor);
    }
    else {
        std::cout << "\nDynamic cast of Item* (Father) failed" << std::endl;
    }
    std::cout << "\tDiscard item" << "\n"
              << "\tBack to inventory\n"
              << "\tLeave inventory\n\n";
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

void View::showDiscardConfirmationMessage() {
    std::cout << "Are you sure you want to discard this item?\n\n"
              << "\t\tYes\n"
              << "\t\tNo\n";
}
