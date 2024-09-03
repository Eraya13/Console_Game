#ifndef VIEW_H
#define VIEW_H
#include <vector>

#include "../02_Entity/Item.h"
#include "../02_Entity/Armor.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Potion.h"

class View
{
private:
    static void toEquipOption(Weapon* weapon);
    static void toEquipOption(Armor* armor);
    static void howToSelect();
public:
    static void inGameMenu_m();         // _m - sign for menu print
    static void listInventoryItems(std::vector<Item*> items);
    static void Inventory_m(int totalPotions);
    static void displayItem(Item* item);
    static void displayItem_m();
    static void playerStats();

    // FUTURE MENU
    // void NewGame_m();
};

#endif // VIEW_H
