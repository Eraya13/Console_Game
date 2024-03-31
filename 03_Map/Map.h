#pragma once
#include "Room.h"
#include "../ErrorLog.h"
#include <vector>
#include <array>

class Map {
private:
	std::vector<std::vector<Room*>> m_map; // storePlace roomek
	Room* m_room;		// sem se ulozi konkretni roomka
	std::array<std::string, 10> m_dir_location;
	void createMap(std::string f_locationsName);
	void createRooms();
	// reading if exist
	void readLocationNames(std::string path_locationsNames);
public:
	Map(std::string filename);
	Room* getRoom(int location, int index);
	// changeRoom()
	


};

