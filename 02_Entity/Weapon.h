#pragma once
#include "../02_Entity/Item.h"

class Weapon: public Item{
protected:
	int m_attackBonus;

public:
	Weapon(std::string name, std::string category, int attackBonus);
	int getAttackBonus() const;
};
