#include "Weapon.h"

Weapon::Weapon (std::string name, std::string category, int attackBonus) : Item (name, category) {
		m_attackBonus = attackBonus;
}

int Weapon::getAttackBonus () const { return m_attackBonus; }

