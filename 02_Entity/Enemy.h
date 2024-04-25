#pragma once
#include "../02_Entity/Entity.h"

class Enemy : public Entity {
protected:
	
public:
	Enemy ();
	// konstruktor pro dedicnost
	Enemy(std::string name, int attack, int defense, int health, int xp);
};

