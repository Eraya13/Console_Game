#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "../02_Entity/Item.h"
#include "../02_Entity/Armor.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Potion.h"

class Inventory
{
private:
    //int m_coins;
    std::vector<Item*> m_items;
    int m_totalNumberItems;
public:
    ~Inventory();
    Inventory();
    // functions to item
    void addItem(Item* item);
    // rovnou provede volání destruktoru item
    void discardItem(Item* item, int itemIndex);
    // vybere item na základě indexu ve vektoru m_items
    int drinkPotion(Item* item);
    int getNumberOfPotions();
    int const getCoins();
    int getNumberOfItems();
    Item* getItem(int itemIndex);
    std::vector<Item*> getItemList();
};

#endif // INVENTORY_H
