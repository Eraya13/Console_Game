#include "Potion.h"

Potion::Potion(std::string name, std::string category, int healthBonus) : Item(name, category) {
    m_healthBonus = healthBonus;
}

int Potion::getHealthBonus() const {return m_healthBonus; }