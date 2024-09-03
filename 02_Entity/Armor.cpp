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

Armor::~Armor() {
    std::cout << "Destruktor Armor zavolán" << std::endl;
}
