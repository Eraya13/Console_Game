#include "Room.h"


// testing konstruktor -> otestuje stav Roomky
Room::Room() {
    createTileField();
}
//*********** real konstruktor
Room::Room(std::string roomFilePath) {
    createTileField(roomFilePath);
    m_EntityManager = new EntityManager();
}

// cteni souboru roomky
void Room::readFile(std::string const pathRoom) {
    std::ifstream fileRoom(pathRoom);
    if (fileRoom.is_open()) {
        for (int row = 0; row < m_tileField.size(); row++) {        // cteni po radcich  0-19 = 20 hodnot!!!        velikost 20, last index 19
            for (int column = 0; column < m_tileField.size(); column++) {   // definitivni urceni hodnot na collumns
                char tileFromFile;
                fileRoom.get(tileFromFile);
                if (tileFromFile != '\n') {
                    tileFromFile = toupper(tileFromFile); // potlaceni malych pismen
                    if (tileFromFile == '.' || tileFromFile == '#' || tileFromFile == 'O' || tileFromFile == 'H'                // non-Entity Types of tile
                        || tileFromFile == 'N' || tileFromFile == 'E' || tileFromFile == 'I' || tileFromFile == 'P') {          // Entity types of tile
                        
                        m_tileField.at(row).at(column) = new Tile(tileFromFile);
                    }
                    else {
                        Errors::Unknown_Char_in_Room_File(row, column, tileFromFile);
                    }
                } // "\n" ignor -  // kvuli get. omezeni (nacita v souboru "\n")
                else {    
                    column--;
                }
            }
        }
        fileRoom.close();
    }
    else {
        Errors::Error_Opening_File();
    }
}

//--------------CREATE ROOM--------------
//testing func 
void Room::createTileField() {
    std::string path = StartingDirectory + "/01.txt";
    std::cout << path;
    if (std::filesystem::exists(path)) {
        readFile(path);
    }
    else {
        Errors::File_Not_Found();
    }
}
   
// real function - pro kazdy soubor
void Room::createTileField(std::string roomFileName) {
    std::string path = roomFileName;
    readFile(path);
}

IEntity* Room::recognizeEntityTypeTile(char tileType, int& e, int& n, int& i) {
    IEntity* entity;
    switch (tileType) {
        case 'E':
            entity = m_EntityManager->getEnemyReference(e);
            e++;
            break;
        case 'N':
            entity = m_EntityManager->getNPCReference(n);
            n++;
            break;
        case 'I':
            // todo same
            // entity = m_EntityManager->getItemReference(i_index);
            i++;
            break;
        default:  // pokud narazí na non-entity tile
            entity = nullptr;
    }
    return entity;
}

void Room::assignEntitiesToTiles() {
    int e_index = 0;
    int n_index = 0;
    int i_index = 0;
    char tileType;
    IEntity* entity;
     // pridat omezení na to, že se už nebude dale prohledavat m_TileField
            // -- prohledavani dokud:       (pokud všechny tři)
            //    if  (e < l_enemies.last_index || n <= l_NPCs.last_index || i <= l_Items.last_index)
            //    else { break;}
    for (int row = 0; row < m_tileField.size(); row++) {                    // cteni po radcich  0-19 = 20 hodnot!!!        velikost 20, last index 19
        for (int column = 0; column < m_tileField.size(); column++) {       // definitivni urceni hodnot na collumns
        tileType = m_tileField.at(row).at(column)->getTileType();
                        entity = recognizeEntityTypeTile(tileType, e_index, n_index, i_index);
            if (entity!= nullptr) {
                m_tileField.at(row).at(column)->setTileEntity(entity);
            }    
        }
    }    
}