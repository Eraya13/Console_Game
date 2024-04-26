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

class Room {
private:	// l_ = list of something
	std::vector <Enemy*> l_enemies;
	std::vector <NPC*> l_NPCs;
	//	std::vector <std::vector<Item*>>;
	void readFile(std::string const pathRoom);
	void createTileField(std::string roomFilePath);
public:
	Room();
	Room(std::string roomFilePath);
	// mista upravujici velikost arraye a pozadavky -> zde a GUI printRoom + future upscale
	std::array<std::array <Tile*, 20>, 20> m_tileField;
	// vytvori roomku na zaklade souboru
	void createTileField();	
	void fillEnemiesList();			// prvotní verze do pole se bude pushbackovat Enemy na základě zadání do konstruktoru "pushback"
	// void fillTileField(); // prvotní verze - nejspíše bude plnit podle TileCategory search




};



