#include "Player.h"


Player::Player(std::string name, int health, int attack) {
	m_name = name;
	m_health = health;
	m_attack = attack;
}

int Player::getHealth() {
	return m_health;
}

int Player::getAttack() {
	return m_attack;
}

std::string Player::getName() {
    return m_name;
}

void Player::setHealth(int minusHealth) {
	m_health -= minusHealth;
}

void Player::battle(Enemy* Enemy) {
	std::cout << "You defeated your enemy.\n";
}
