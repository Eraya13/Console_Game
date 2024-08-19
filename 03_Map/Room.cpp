#include "Room.h"

Room::Room(std::string roomFilePath) {
    createTileField(roomFilePath);
    m_EntityManager = new EntityManager();
}

/// Funkce čte soubor po řádcích a v řádcích po znacích
/// každý znak reprezentuje Tilu - tzn. co na ní je Entita nebo to je Wall či grass
/// Ošetřeno o to, že jsou jen dané typy til - cokoliv mimo povolené je chyba v souboru (nutná oprava souboru)
void Room::createTileField (std::string roomFilePath) {
    std::ifstream fileRoom (roomFilePath);
    if (fileRoom.is_open()) {
        for (int row = 0; row < m_tileField.size(); row++) {        // cteni po radcich  0-19 = 20 hodnot!!!        velikost 20, last index 19
            for (int column = 0; column < m_tileField.size(); column++) {   // definitivni urceni hodnot na collumns
                char tileFromFile;
                fileRoom.get(tileFromFile);
                if (tileFromFile != '\n') {
                    tileFromFile = toupper(tileFromFile);   // potlaceni malych pismen
                    if (tileFromFile == '.' || tileFromFile == '#' || tileFromFile == 'O' || tileFromFile == 'H'                // non-Entity Types of tile
                        || tileFromFile == 'N' || tileFromFile == 'E' || tileFromFile == 'I' || tileFromFile == 'P') {          // Entity types of tile

                        m_tileField.at(row).at(column) = new Tile(tileFromFile);
                    }
                    else {
                        //Errors::Unknown_Char_in_Room_File(row, column, tileFromFile);
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
        //Errors::Error_Opening_File();
        std::cerr << "File cannot be open" << std::endl;
    }
}

// další funkce - s Entity Managerem

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
