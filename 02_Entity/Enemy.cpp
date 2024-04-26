#include "Enemy.h"


Enemy::Enemy(std::string name, int attack, int defense, int health, int xp) 
	: Entity (name, attack, defense, health, xp) {
}

void Enemy::printInfo() {
	std::cout << "Info Enemy" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Attack: " << m_attack << std::endl;
	std::cout << "Defense: " << m_defense << std::endl;
    std::cout << "Health: " << m_health << std::endl;
    std::cout << "XP: " << m_xp << std::endl;
}