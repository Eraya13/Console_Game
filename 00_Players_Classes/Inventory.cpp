#include "Inventory.h"

Inventory::Inventory() {
    m_totalNumberItems=0;
}

void Inventory::addItem(Item* item) {
    m_items.push_back(item);
    m_totalNumberItems++;
}

int Inventory::drinkPotion(Item* item) {
    if (Potion* potion = dynamic_cast<Potion*>(item)) {
        int health = potion->getHealthBonus();
        return health;
    }
    return 0;
}

void Inventory::discardItem(Item* item) {
    delete item;
    m_totalNumberItems--;
}

int Inventory::getNumberOfPotions() {
    int totalPotions = 0;
    for (Item* item : m_items) {
        if(item->getCategory()=="Potion")
        {
            totalPotions+=1;
        }
    }
    return totalPotions;
}

Inventory::~Inventory() {
    // Uvolnění paměti
    for (Item* item : m_items) {
        delete item;
    }
}

std::vector<Item*> Inventory::getItemList() {
    return m_items;
}
