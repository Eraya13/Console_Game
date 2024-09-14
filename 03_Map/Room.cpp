#include "Room.h"

Room::Room(std::string roomFilePath) {
    createTileField(roomFilePath);
    m_EntityManager = new EntityManager();
}

void Room::createTileField (std::string roomFilePath) {
    std::ifstream fileRoom (roomFilePath);
    if (fileRoom.is_open()) {
        for (int row = 0; row < m_tileField.size(); row++) {        // reading by rows 0-19 = 20 rows
            for (int column = 0; column < m_tileField.size(); column++) {   // reading by columns = exact value (also 0-19)
                char tileFromFile;
                fileRoom.get(tileFromFile);
                if (tileFromFile != '\n') {
                    tileFromFile = toupper(tileFromFile);
                    if (tileFromFile == '.' || tileFromFile == '#' || tileFromFile == 'O' || tileFromFile == 'H'
                        || tileFromFile == 'E' || tileFromFile == 'I' || tileFromFile == 'P') {

                        m_tileField.at(row).at(column) = new Tile(tileFromFile);
                    }
                    else {
                        //Errors::Unknown_Char_in_Room_File(row, column, tileFromFile);
                    }
                } // Ignore "\n" - // Due to the limitations of get (it reads "\n" from the file)
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

IEntity* Room::recognizeEntityTypeTile(char tileType, int& e, int& i) {
    IEntity* entity;
    switch (tileType) {
        case 'E':
            entity = m_EntityManager->getEnemyReference(e);
            e++;
            break;
        case 'I':
            // todo same
            // entity = m_EntityManager->getItemReference(i_index);
            i++;
            break;
        default:  // if it encounters a non-entity tile
            entity = nullptr;
    }
    return entity;
}

void Room::assignEntitiesToTiles() {
    int e_index = 0;
    int i_index = 0;
    char tileType;
    IEntity* entity;
     // pridat omezení na to, že se už nebude dale prohledavat m_TileField
            // -- prohledavani dokud:       (pokud všechny tři)
            //    if  (e < l_enemies.last_index || n <= l_NPCs.last_index || i <= l_Items.last_index)
            //    else { break;}
    for (int row = 0; row < m_tileField.size(); row++) {
        for (int column = 0; column < m_tileField.size(); column++) { 
        tileType = m_tileField.at(row).at(column)->getTileType();
                        entity = recognizeEntityTypeTile(tileType, e_index, i_index);
            if (entity!= nullptr) {
                m_tileField.at(row).at(column)->setTileEntity(entity);
            }    
        }
    }    
}
