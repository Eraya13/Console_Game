#pragma once
#include "../02_Entity/Entity.h"

class NPC : public IEntity {
protected:
    std::string m_name;
	// Inventory* m_inventory;
	int xp;		// za určitý výběr volby - "dobré charisma"  se předá hráči xp
public:
	NPC(std::string name);
	std::string getName() const;
};
