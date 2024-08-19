#pragma once
#include "Room.h"
#include <vector>
#include <fstream>
#include <array>
#include "Room.h"

class Map {
private:
    std::vector<std::vector<Room*>> m_map;          // vektor vektoru roomek - 1. vektor = lokace 2. vektor = rooms
    Room* m_room;                                   // sem se ulozi konkretni roomka
    std::array<std::string, 10> m_dir_location;     // nazvy slozek s lokacemi

    void createMap(std::string path_locationNames);
    void createRooms();
    bool readRoomFile(std::string path);
    bool readLocationNames(std::string const path_locationNames);
public:
    Map(std::string fileName);
    Room* getRoom(int location, int index) const;

    // deklarace konstanty relativní cesty filů k celé mapě - nemůžu ji tady hned přiřadit hodnotu!!
    static const std::string MAP_FOLDER;
    static const std::string LOCATION_NAMES;
    // changeRoom()


};

