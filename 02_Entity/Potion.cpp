#include "Potion.h"

Potion::Potion(std::string name, int healthBonus) : Item(name) {
    m_healthBonus = healthBonus;
    setCategory();
}
// ** setters **
void Potion::setInfo() {
	m_info = "Something specific for Potion.";
}
void Potion::setCategory() { m_category = "Potion";} 

// ** getters **
int Potion::getHealthBonus() const {return m_healthBonus; }

