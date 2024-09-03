#include "Armor.h"

Armor::Armor(std::string name, int defenseBonus) : Item (name) {
		m_defenseBonus = defenseBonus;
}

// ** setters **
// ** setters **
void Armor::setCategory(std::string category) {
    m_category = "Armor";
}

void Armor::setInfo (std::string info) {
    m_info = "Some information about weapon";
}

// ** getters **
int Armor::getDefenseBonus () const { return m_defenseBonus; }

void Armor::printBriefInfo() {
    std::cout  << "|\t" << getCategory() << "   |\t" << getName() <<"   |\t+ " << getDefenseBonus() << "defense" << std::endl;
}

Armor::~Armor() {
}

