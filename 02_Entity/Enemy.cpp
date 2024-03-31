#include "Enemy.h"


Enemy::Enemy(std::string name, int health, int attack) {
	m_name = name;
	m_health = health;
	m_attack = attack;
}

int Enemy::getHealth() {
	return m_health;
}

int Enemy::getAttack() {
	return m_attack;
}

void Enemy::setHealth(int minusHealth) {
	m_health -= minusHealth;
}