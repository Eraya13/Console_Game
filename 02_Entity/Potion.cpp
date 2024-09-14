#include "Potion.h"

Potion::Potion (std::string name, int healthBonus) : Item (name) {
    m_healthBonus = healthBonus;
    m_category = "Health Potion";
    m_info = "";
}

Potion::Potion(std::string name) : Item(name) {
    m_healthBonus = 50;
    m_category = "Potion";
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
    //std::cout << "Destruktor Potion zavolán" << std::endl;
}

void Potion::printBriefInfo() {
    std::cout  << "\t" << getCategory() << "\t\t|\t" << getName() << "\t\t|\t+ " << getHealthBonus() << " HP" << std::endl;
}
