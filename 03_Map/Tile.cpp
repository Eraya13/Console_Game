#include "Tile.h"

Tile::Tile(char type) {
	m_tileType = type;
	m_entity = nullptr;
}

char Tile::getTileType() const { return m_tileType; }
void Tile::setTileType(char newType) {
	m_tileType = newType;
}

void Tile::setTileEntity(IEntity *entity) {
    if (entity == nullptr) {
		m_entity = entity;
	}
	else {
		 std::cout << "Warning: Attempting to assign a entity to tile that is occuppied by entity!" << std::endl;
	}
}

void Tile::emptyTileEntity() {
	//m_entity = nullptr;
}
