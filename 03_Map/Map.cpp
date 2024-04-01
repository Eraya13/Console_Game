#include "Map.h"

Map::Map(std::string filename) {
	createMap(filename);
}

// precteni jmen lokaci (dirs) + ulozeni techto jmen do arraye m_dir_location
void Map::readLocationNames(std::string path_locationsNames) {	
	std::ifstream f_dirLocations;			   // deklarace citatka pro konkretni soubor
	f_dirLocations.open(path_locationsNames); // nacteni cesty
	if (f_dirLocations.is_open()) {
		int index = 0;					// starting index lokace = Village
		while (!(f_dirLocations.eof())) {
			std::string name;
			getline(f_dirLocations, name);			// cteni 1 radku = 1 lokace
			m_dir_location.at(index) = name;		// array imp part of path lokace
			index++;
		}
		f_dirLocations.close();
	}
}
// hlavni prostredi vytvareni mapy
void Map::createMap(std::string f_locationsName) {
	std::string path = MapFolder + f_locationsName;
	// debugPrint
	//std::cout << completePath << "\n\n";
	if (std::filesystem::exists(path)) {
		readLocationNames(path);
		createRooms();
	}
	else {
		Errors::File_Not_Found();
	}
}

// vytvareni Roomek a ukladani do 2D vektoru m_map
void Map::createRooms() {
	std::vector<Room*> lokace;		// lokalni promenna pro push_back roomek do m_mapy
	std::string filePathRoom;        // Village = home
	int sizeL = 4;			// pocet lokaci ve hre (tolik mame slozek)

	for (int indexL = 0; indexL < sizeL && !m_dir_location.empty(); indexL++) {					// indexL = Location		// indexR = Room
		lokace.clear();											//vycisti vektor lokaci - pushuju tam nove m_rooms
		for (int indexR = 1; indexR <= 9; indexR++) {
			filePathRoom = MapFolder + m_dir_location.at(indexL) + "/0" + std::to_string(indexR) + ".txt";
			if (std::filesystem::exists(filePathRoom)) {
				m_room = new Room(filePathRoom);
				lokace.push_back(m_room);
			}
			else { // **Debug Errors**
				//Errors::File_Not_Found();
				//std::cout << Errors::amountErrors;		// vzdy errors  by melo byt jako pocet lokaci
				break;
			}
		}
		/*Debug prints
		/std::cout << filePathRoom << std::endl;
		std::cout << "Adding location: " << m_dir_location.at(indexL) <<  " to m_map."  << std::endl;
		std::cout << "Number of rooms in lokace: " << lokace.size() << std::endl;
		system("pause");*/
		// Pridani lokace m_mapy
		m_map.push_back(lokace);
	}
}

Room* Map::getRoom(int location, int index) {
	return m_map.at(location).at(index);
}
