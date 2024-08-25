#include "Map.h"

// inicializace konstant - relativních cest
const std::string Map::MAP_FOLDER = "Files/Map/Locations/";
//const std::string Map::LOCATION_NAMES = "LocationsNames.txt";

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

// Funkce se pokusí přečíst soubor s názvy lokací, které hráč může navštívit
// názvy lokací odpovídají složce, kde jsou jednotlivé roomky
// Funkce type bool = tzn. slouží také jako ověření, zda vůbec lze vytvořit roomky (tzn. podmínka pro vytvoření roomek)
bool Map::readLocationNames(std::string const path_locationNames) {
    std::ifstream f_LocationNames(path_locationNames);
    if (!f_LocationNames.is_open()) {
        return false;
        std::cout << "File cannot be open - no file for relative path: " << path_locationNames;
    }

    int indexLokace = 0;					// starting index lokace = Village
    while (!(f_LocationNames.eof())) {      // čtení dokud se nenarazí na konec souboru = eof
        std::string name;
        getline(f_LocationNames, name);			// cteni 1 radku = 1 lokace
        m_dir_location.at(indexLokace) = name;		// ukládání jmen na jednotlivé indexy lokací 0-9
        indexLokace++;
    }

    // pokud se vše povede - úspěšně se zavře soubor a vrací se true - vše OK
    f_LocationNames.close();
    return true;
}

// přečte soubor a vrací true, pokud jej lze otevřít
bool Map::readRoomFile(std::string path) {
    std::ifstream roomFile(path);
    // pokud nepůjde otevřít - dostaneme zde chybovou hlášku a nemá smysl vytvářet tuto roomku
    if (!roomFile.is_open()) {
        std::cerr << "File in relative path - "<< path << " has not been found - probably does not exist" << std::endl;
        return false;
    }
    return true;
}

void Map::createRooms() {
    std::vector<Room*> lokace;		// lokalni promenna pro push_back roomek do m_mapy
    std::string path_Room;          // Village = home
    int locationAmount = 4;			// pocet lokaci ve hre (tolik mame slozek)

    for (int indexL = 0; indexL < locationAmount; indexL++) {					// indexL = Location		// indexR = Room
        lokace.clear();											//vycisti vektor lokaci - pushuju tam nove m_rooms
        for (int indexR = 1; indexR <= 9; indexR++) {
            path_Room = Map::MAP_FOLDER + m_dir_location.at(indexL) + "/0" + std::to_string(indexR) + ".txt"; // cesta ke konkrétní roomce v určité lokaci

            if(!readRoomFile(path_Room)) {  // nelze otevřít - yes - přerušení cyklu - zkusí se otevřít další lokace
                break;
            }
            // vytváření samotné roomky na základě souboru roomky
            m_room = new Room(path_Room);
            lokace.push_back(m_room);       // vektor roomek
        }
        //Debug prints
        //std::cout << path_Room << std::endl;
        std::cout << "Adding location: " << m_dir_location.at(indexL) <<  " to m_map."  << std::endl;
        std::cout << "Number of rooms in lokace: " << lokace.size() << std::endl;
        system("pause");

        // Pridani lokace do m_mapy
        m_map.push_back(lokace); // vektor vektoru roomek
    }
}

Room* Map::getRoom(int location, int index) const {
	return m_map.at(location).at(index);
}
