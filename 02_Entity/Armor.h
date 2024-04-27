#pragma once
#include "../02_Entity/Item.h"

class Armor: public Item{
protected:
	int m_defenseBonus;

public:
	Armor(std::string name, int defenseBonus);
	int getDefenseBonus() const;
	void setInfo() override;
	void setCategory () override;
};
