#pragma once
#include <iostream>
#include <array>
#include <fstream>
#include <filesystem>
#include "../GlobalVariables.h"
#include "Tile.h"
#include "../ErrorLog.h"


class Room {
private:
	//	std::vector <std::vector<Enemy*>> m_enemyList;
	//	std::vector <std::vector<NPC*>> m_NPCList;
	void readFile(std::string pathRoom);
	void createTileField(std::string roomFilePath);
public:
	Room();
	Room(std::string roomFilePath);
	std::array<std::array <Tile*, 20>, 20> m_tileField;
	// vytvori roomku na zaklade souboru
	void createTileField();	
	//void fill_ListEnemy();




};



