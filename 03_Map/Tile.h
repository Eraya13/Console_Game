#pragma once
#include <iostream>
#include "../01_Enums/TileType.h"
#include "../02_Entity/Enemy.h"

class Tile {
private:	
	// TileTypes 
	// Entity:	E = Enemy	I = Item	P = Player		N = NPC
	// None:	# = Wall	. = empty space (NONE)		
	// Travel:	O = Portal	 H = Home
	char m_tileType;
	// IEntity *m_Entity;			// Tile obsahuje 1 Entity if E, N, I
public:
	Tile(char tile);
	char getTileType();
	void setTileType(char newType);			// zmena TileType -> pohyb hrace / akce hrace
	void emptyTileEntity();					// odstrani odkaz na Entitu z Tily
	Enemy* castEnemy();
	//Entity castNPC();
	//Entity castItem();
};

