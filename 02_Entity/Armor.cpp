#include "Armor.h"

Armor::Armor(std::string name, std::string category, int defenseBonus) : Item (name, category) {
		m_defenseBonus = defenseBonus;
}

// ** setters **
void Armor::setInfo() {
	m_info = "Something specific for Armor.";
}
void Armor::setCategory() { m_category = "Armor"; }

// ** getters **
int Armor::getDefenseBonus () const { return m_defenseBonus; }

