#pragma once
#include "../02_Entity/Item.h"

class Armor: public Item{
protected:
	int m_defenseBonus;
    bool m_equipped;
public:
	Armor(std::string name, int defenseBonus);
	int getDefenseBonus() const;
    void setInfo(std::string info) override;
    void setEquipped();
    void setUnequipped();
    bool isEquipped();
    void setCategory(std::string category) override;
    void printBriefInfo() override;
    ~Armor();
};
