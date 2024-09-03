#include "Inventory.h"

Inventory::Inventory() {
    m_items.push_back(new Weapon("Moonlight sword", 30));
}

void Inventory::addItem(Item* item) {
    m_items.push_back(item);
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
