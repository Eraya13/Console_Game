#pragma once
#include "Item.h"

class Weapon: public Item{
protected:
	int m_attackBonus;

public:
    Weapon(std::string name, int attackBonus);
    int getAttackBonus() const;
    void setInfo(std::string info) override;
    void setCategory(std::string category) override;
    void printBriefInfo() override;
    ~Weapon();
};
