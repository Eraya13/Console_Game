#include "Entity.h"

Entity::Entity(std::string name, int attack, int defense, int health, int xp) {
    m_name = name;
    m_attack = attack;
    m_defense = defense;
    m_health = health;
    m_xp = xp;
}

// gettery atributů
int Entity::getAttack() const { return m_attack; }
int Entity::getDefence() const { return m_defense; }
int Entity::getHealth() const { return m_health; }
std::string Entity::getName() const { return m_name; }
int Entity::getXP() const { return m_xp; }

// settery atributů - využití při upgrade stats:
void Entity::setAttack(int attack) {
    if (attack >=0) m_attack = attack;
    else {
        std::cout << "Invalid value for attack: " << m_attack << "is negative number - not a valid input" << std::endl;
    }
}

void Entity::setDefense(int defense) {
    if (defense >=0) m_defense = defense;
    else {
        std::cout << "Invalid value for defense: " << m_defense << "is negative number - not a valid input" << std::endl;
    }
}