#ifndef POTION_H
#define POTION_H

#include "Item.h"
class Potion : public Item {
protected:
int m_healthBonus;

public:
Potion(std::string name, int healthBonus);
int getHealthBonus() const;
void setInfo(std::string info) override;
void setCategory(std::string category) override;
~Potion();
};

#endif // POTION_H
