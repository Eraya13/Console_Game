#pragma once
#include <iostream>
#include "../01_Enums/TileType.h"
#include "../02_Entity/Enemy.h"

class Tile {
private:
    // TileTypes
    // Entity:	E = Enemy	I = Item	P = Player
	// None:	# = Wall	. = empty space (NONE)		
	// Travel:	O = Portal	 H = Home
	char m_tileType;
    IEntity* m_entity;			// Tile obsahuje 1 Entity if E, I				// jsem si vedoma redunance, ze #, ., O, H - nepotřebují atribut m_entity...
public:
	Tile(char tile);
	char getTileType() const;
	void setTileType(char newType);			// zmena TileType -> pohyb hrace / akce hrace
	void setTileEntity(IEntity *entity);		// ulozim zde jednoho z potomku
	void emptyTileEntity();					// odstrani odkaz na Entitu z Tily
	Enemy* castEnemy();
	//Entity castNPC();
	//Entity castItem();
};

