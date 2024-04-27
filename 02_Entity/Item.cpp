#include "Item.h"

Item::Item(std::string name, std::string category) {
	m_name = name;
	m_category = category;
}

std::string Item::getName() const { return m_name; }
std::string Item::getCategory() const { return m_category; }






