#include "Item.h"

Item::Item(std::string name) {
	m_name = name;
}

std::string Item::getName() const { return m_name; }
std::string Item::getCategory() const { return m_category; }

void Item::printInfo() {
    std::cout<< "The item is" << m_name ;
}

// Implementace čistě virtuálního destruktoru
Item::~Item() {
    //std::cout << "Destroyed";
}

