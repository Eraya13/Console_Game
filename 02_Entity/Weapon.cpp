#include "Weapon.h"

Weapon::Weapon (std::string name, int attackBonus) : Item (name) {
		m_attackBonus = attackBonus;
		setCategory();
}
// ** setters **
void Weapon::setInfo () {
	m_info = "Something specific for Weapon.";
}
void Weapon::setCategory() { m_category = "Weapon"; }

// ** getters **
int Weapon::getAttackBonus () const { return m_attackBonus; }


