#include "Inventory.h"

Inventory::Inventory() {
    m_totalNumberItems=0;
    addItem(new Potion("Health Potion"));
    addItem(new Weapon("Silver katana", 40));
    addItem(new Weapon("Blood Dagger", 20));
    addItem(new Armor("Iron gear", 40));
    addItem(new Armor("Welvet gear", 10));
}

void Inventory::addItem(Item* item) {
    m_items.push_back(item);
    m_totalNumberItems++;
}

void Inventory::findPotion(Item* &potion, int& index) {
    potion = nullptr;
    index = -1;

    for (int i = 0; i < m_items.size(); i++) {
        if (m_items.at(i)->getCategory()== "Potion") {
            potion = m_items.at(i);
            index = i;
            return;
        }
    }
}

void Inventory::discardItem(Item* item, int itemIndex) {
    // zmizí menu - zobrazí se pouze informace o Itemu (bez menu)
    // ověření volby
    // Pokud bude odpověď stále Ano -> provede se
    if (itemIndex >= 0 && itemIndex < m_items.size()) {
        m_items.erase(m_items.begin() + itemIndex);
        delete item;
        m_totalNumberItems--;
    }
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
