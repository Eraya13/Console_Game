#include "Weapon.h"

Weapon::Weapon (std::string name, std::string category, int attackBonus) : Item (name, category) {
		m_attackBonus = attackBonus;
}
// ** setters **
void Weapon::setInfo () {
	m_info = "Something specific for Weapon.";
}
void Weapon::setCategory() { m_category = "Weapon"; }

// ** getters **
int Weapon::getAttackBonus () const { return m_attackBonus; }


