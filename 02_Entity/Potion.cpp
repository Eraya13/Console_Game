#include "Potion.h"

Potion::Potion(std::string name, std::string category, int healthBonus) : Item(name, category) {
    m_healthBonus = healthBonus;
}
// ** setters **
void Potion::setInfo() {
	m_info = "Something specific for Potion.";
}
void Potion::setCategory() { m_category = "Potion";} 

// ** getters **
int Potion::getHealthBonus() const {return m_healthBonus; }

