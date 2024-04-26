#include "Tile.h"

Tile::Tile(char type) {
	m_tileType = type;
	//m_entity = nullptr;
}

char Tile::getTileType() const { return m_tileType; }

void Tile::setTileType(char newType) {
	m_tileType = newType;
}

void Tile::emptyTileEntity() {
	//m_entity = nullptr;
}




// nepouzivat!!!
void Tile::setTileEntity(IEntity *entity) {
	switch (m_tileType) {
		case 'E':
		    m_entity = entity;
			break;
		case 'N':
		    m_entity = entity;
			break;
		case 'I':
		    m_entity = entity;
			break;
	}

}