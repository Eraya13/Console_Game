#include "Item.h"

Item::Item(std::string name) {
	m_name = name;
}

std::string Item::getName() const { return m_name; }
std::string Item::getCategory() const { return m_category; }

void Item::printInfo() {
    std::cout << "This is item parent.";
}

Item::~Item() {
    //std::cout << "Destruktor Potion zavolán" << std::endl;
}
