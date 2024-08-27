#pragma once
#include "../02_Entity/Enemy.h"

class Player {
private:
	std::string m_name;
	int m_health;
	int m_attack;
    int m_defense;
public:
    Player(std::string name, int health, int attack);       // todo defense, level, xp
	
	// gettery
	int getHealth();
	int getAttack();
    std::string getName();

	// settery
	void setHealth(int minusHealth);

	// entity funkce:
	void battle(Enemy* Enemy);
	void talk(/*NPC* NPC*/);
};

