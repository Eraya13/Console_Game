#pragma once
#include "../02_Entity/Item.h"

class Potion: public Item{
protected:
	int m_healthBonus;

public:
	Potion(std::string name, int healthBonus);
	int getHealthBonus() const;
	void setInfo() override;
	void setCategory() override;
};