#include "Map.h"

// Initialize constants for file paths
const std::string Map::MAP_FOLDER = "Files/Map/Locations/"; // Path to the folder containing location files
const std::string Map::LOCATION_NAMES = "LocationsNames.txt"; // File containing names of location directories

Map::Map(std::string fileName) {
    std::string path_locationNames = Map::MAP_FOLDER + fileName;
    createMap(path_locationNames);
}


void Map::createMap(std::string path_locationNames) {
    if(readLocationNames(path_locationNames)) {
        createRooms();
    }
    else {
        std::cerr << "File not found. The path leads to not-existing file." << std::endl;
    }
}

bool Map::readLocationNames(std::string const path_locationNames) {
    std::ifstream f_LocationNames(path_locationNames);
    if (!f_LocationNames.is_open()) {
        return false;
        //std::cout << "File cannot be open - no file for relative path: " << path_locationNames;
    }

    int indexLokace = 0;					// starting index location
    while (!(f_LocationNames.eof())) {
        std::string name;
        getline(f_LocationNames, name);			// 1 line = 1 location name
        m_dir_location.at(indexLokace) = name;		// storing names at the singular indexes of location 0- 9
        indexLokace++;
    }

    // if all is succesful - file will be closed a method returns true
    f_LocationNames.close();
    return true;
}

bool Map::readRoomFile(std::string path) {
    std::ifstream roomFile(path);
    if (!roomFile.is_open()) {
        //std::cerr << "File in relative path - "<< path << " has not been found - probably does not exist" << std::endl;
        return false;
    }
    return true;
}

void Map::createRooms() {
    std::vector<Room*> lokace;	
    std::string path_Room;         
    int locationAmount = 4;	// total number of location for the game

    for (int indexL = 0; indexL < locationAmount; indexL++) {		// indexL = index of Location		
        lokace.clear();
        for (int indexR = 1; indexR <= 9; indexR++) { 		// indexR = index of Room
            path_Room = Map::MAP_FOLDER + m_dir_location.at(indexL) + "/0" + std::to_string(indexR) + ".txt"; // path to specific room in the location

            if(!readRoomFile(path_Room)) {  // if it cannot be open - break of the cycle and new room from next location will be read
                break;
            }
  
            m_room = new Room(path_Room);
            lokace.push_back(m_room);
        }
        
        //Debug prints
        //std::cout << path_Room << std::endl;
        /*std::cout << "Adding location: " << m_dir_location.at(indexL) <<  " to m_map."  << std::endl;
        std::cout << "Number of rooms in lokace: " << lokace.size() << std::endl;
        system("pause");*/
        m_map.push_back(lokace);
    }
}

Room* Map::getRoom(int location, int index) const {
	return m_map.at(location).at(index);
}
