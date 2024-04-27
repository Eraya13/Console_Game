#pragma once
#include "../02_Entity/Item.h"

class Armor: public Item{
protected:
	int m_defenseBonus;

public:
	Armor(std::string name, std::string category, int defenseBonus);
	int getDefenseBonus() const;
};
