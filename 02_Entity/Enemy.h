#pragma once
#include <iostream>

class Enemy {
private:
	std::string m_name;
	int m_health;
	int m_attack;
public:
	Enemy(std::string name, int health, int attack);
	int getHealth();
	int getAttack();
	void setHealth(int minusHealth);

};

