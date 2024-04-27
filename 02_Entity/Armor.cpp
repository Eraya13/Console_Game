#include "Armor.h"

Armor::Armor(std::string name, std::string category, int defenseBonus) : Item (name, category) {
		m_defenseBonus = defenseBonus;
}

int Armor::getDefenseBonus () const { return m_defenseBonus; }

