#pragma once
#include <array>
//#include "../02_Entity/NPC.h"
//#include "../ErrorLog.h"
#include <fstream>
#include "Tile.h"
#include "EntityManager.h"


class Room {
private:
	EntityManager* m_EntityManager;
    IEntity* recognizeEntityTypeTile(char tileType, int& e_index, int& i_index);
	void createTileField(std::string roomFilePath);
public:											// tiles are public - no secret from Room - room has access everywhere...
	Room(std::string roomFilePath);
	// mista upravujici velikost arraye a pozadavky -> zde a GUI printRoom + future upscale
	std::array<std::array <Tile*, 20>, 20> m_tileField;
    void createTileField();             // vytvori roomku na zaklade souboru
	void assignEntitiesToTiles(); 		// bude plnit m_tieldField entitami na základě getTileType();
};



