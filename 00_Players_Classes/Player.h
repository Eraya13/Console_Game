#pragma once
#include "../02_Entity/Enemy.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Armor.h"
#include "Inventory.h"

class Player {
private:
	std::string m_name;
	int m_health;
	int m_attack;
    int m_defense;
    Inventory* m_inventory;
    Armor* m_armor;
    Weapon* m_weapon;
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
};

