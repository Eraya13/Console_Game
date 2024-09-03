#include "Weapon.h"

Weapon::Weapon (std::string name, int attackBonus) : Item (name) {
		m_attackBonus = attackBonus;
        m_category = "Weapon";
        m_info = "";
}
// ** setters **
void Weapon::setCategory(std::string category) { m_category = "Weapon"; }

void Weapon::setInfo (std::string info) {
    m_info = "Some information about weapon";
}

// ** getters **
int Weapon::getAttackBonus () const { return m_attackBonus; }

Weapon::~Weapon() {
    std::cout << "Destruktor Weapon zavolán" << std::endl;
}
