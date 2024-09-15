#include "Weapon.h"

Weapon::Weapon (std::string name, int attackBonus) : Item (name) {
    m_attackBonus = attackBonus;
    m_equipped = false;
    m_category = "Weapon";
    m_info = "";
}


void Weapon::setCategory(std::string category) { m_category = "Weapon"; }

void Weapon::setInfo (std::string info) {
    m_info = "Some information about weapon";
}

void Weapon::setEquipped() { m_equipped = true; }

void Weapon::setUnequipped() { m_equipped = false; }


// ** getters **
int Weapon::getAttackBonus() const { return m_attackBonus; }

bool Weapon::isEquipped() { return m_equipped; }

Weapon::~Weapon() {
    std::cout << "Destruktor Weapon zavolán" << std::endl;
}

void Weapon::printBriefInfo() {
    std::cout  << "\t" << getCategory() << "\t\t|\t" << getName() << "\t\t|\t+ " << getAttackBonus() << " damage" << std::endl;
}
