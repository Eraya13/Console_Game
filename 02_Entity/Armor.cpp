#include "Armor.h"

Armor::Armor(std::string name, int defenseBonus) : Item (name) {
    m_defenseBonus = defenseBonus;
    m_category = "Armor";
    m_equipped = false;
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

void Armor::setEquipped() { m_equipped = true; }

void Armor::setUnequipped() { m_equipped = false; }

bool Armor::isEquipped() { return m_equipped; }

void Armor::printBriefInfo() {
    std::cout  << "\t" << getCategory() <<  "\t\t|\t" << getName() << "\t\t|\t+ " << getDefenseBonus() << " defense" << std::endl;
}

Armor::~Armor() {
}

