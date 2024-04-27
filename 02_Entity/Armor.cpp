#include "Armor.h"

Armor::Armor(std::string name, int defenseBonus) : Item (name) {
		m_defenseBonus = defenseBonus;
		setCategory();
}

// ** setters **
void Armor::setInfo() {
	m_info = "Something specific for Armor.";
}
void Armor::setCategory() { m_category = "Armor"; }

// ** getters **
int Armor::getDefenseBonus () const { return m_defenseBonus; }

