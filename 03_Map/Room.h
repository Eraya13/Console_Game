#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <filesystem>
#include "../GlobalVariables.h"		// chce to předělat!!! - nebudu používat jako variables GLOBAL!!!! spíše to budou nějaké cesty proměnné...
#include "Tile.h"
#include "../ErrorLog.h"
#include "../02_Entity/Enemy.h"
#include "../02_Entity/NPC.h"

#include "EntityManager.h"


class Room {
private:
	EntityManager* m_EntityManager;
	void readFile(std::string const pathRoom);
	IEntity* recognizeEntityTypeTile(char tileType, int& e_index, int& n_index, int& i_index);
	void createTileField(std::string roomFilePath);
public:											// tiles are public - no secret from Room - room has access everywhere...
	Room();
	Room(std::string roomFilePath);
	// mista upravujici velikost arraye a pozadavky -> zde a GUI printRoom + future upscale
	std::array<std::array <Tile*, 20>, 20> m_tileField;
	void createTileField();		// vytvori roomku na zaklade souboru
	void assignEntitiesToTiles(); 		// bude plnit m_tieldField entitami na základě getTileType();



};



