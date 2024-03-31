#pragma once
#include <iostream>
#include "../02_Entity/Enemy.h"

class Player {
private:
	std::string m_name;
	int m_health;
	int m_attack;
public:
	Player(std::string name, int health, int attack);
	
	// gettery
	int getHealth();
	int getAttack();

	// settery
	void setHealth(int minusHealth);

	// entity funkce:
	void battle(Enemy* Enemy);
	void talk(/*NPC* NPC*/);
};

