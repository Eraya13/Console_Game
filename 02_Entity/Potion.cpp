#include "Potion.h"

Potion::Potion (std::string name, int healthBonus) : Item (name) {
    m_healthBonus = healthBonus;
    m_category = "Health Potion";
    m_info = "";
}
// ** setters **
void Potion::setCategory(std::string category) { m_category = "Potion"; }

void Potion::setInfo (std::string info) {
    m_info = "Some information about Potion";
}

// ** getters **
int Potion::getHealthBonus () const { return m_healthBonus; }

Potion::~Potion() {
    std::cout << "Destruktor Potion zavolán" << std::endl;
}
