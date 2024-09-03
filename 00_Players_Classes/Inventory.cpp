#include "Inventory.h"

Inventory::Inventory() {
    m_totalNumberItems=0;
    addItem(new Potion("Health Potion"));
    addItem(new Weapon("Silver katana", 40));
    addItem(new Armor("Welvet gear", 40));
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

int Inventory::getNumberOfItems() { return m_totalNumberItems; }

Item* Inventory::getItem(int itemIndex) {
    if (itemIndex < 0 || itemIndex >= static_cast<int>(m_items.size())) {
        throw std::out_of_range("Index out of range");
    }

    Item* item = m_items.at(itemIndex);
    if (item == nullptr) {
        throw std::runtime_error("Item at the given index does not exist");
    }
    return item;
}

std::vector<Item*> Inventory::getItemList() { return m_items; }

Inventory::~Inventory() {
    // Uvolnění paměti
    for (Item* item : m_items) {
        delete item;
    }
}
