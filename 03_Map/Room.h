#pragma once
#include <array>
#include <fstream>

#include "Tile.h"
#include "EntityManager.h"

/**
 * @brief Represents a single room in a larger location within the game, consisting of a grid of tiles.
 * 
 * A room is a single navigable area in which the player can move around. Rooms are interconnected by portals,
 * allowing the player to travel between different rooms. Multiple rooms together form a "location," and all locations
 * combined create the full game map—the overall area in which the player can explore and interact.
 * 
 * Each tile in the room can either represent empty space, a wall, or contain an entity such as an enemy, item, or player.
 * The room layout is loaded from a file, and entities are managed by an EntityManager. */
class Room {
private:
    /**
    * @brief Pointer to the entity manager responsible for handling entities within the room.
    *
    * The entity manager provides access to the entities (such as enemies and items) that need to be placed on the room's tiles. */
    EntityManager* m_EntityManager;

    IEntity* recognizeEntityTypeTile(char tileType, int& e_index, int& i_index);

    /**
    * @brief Reads the room layout from a file and creates the corresponding tile grid.
    *
    * This function reads a file line by line, with each character representing a tile in the grid. Valid characters include:
    *
    * '.' (empty space),'#' for walls, 'O' for portal, 'H' for home (representing a safe central area)
    * 'E' for an enemy, 'I' for an item, 'P' for the player
    *
    * Any character not matching one of the valid tile types will be treated as an error in the file.
    *
    * @param roomFilePath The path to the file containing the room's layout. */
void createTileField(std::string roomFilePath);
public:
    /**
    * @brief Constructs a room by reading its layout from a file.
    *
    * Initializes the room by creating its grid of tiles and assigning an entity manager for managing entities in the room.
    *
    * @param roomFilePath The path to the file containing the room's layout. */
	Room(std::string roomFilePath);

    /**
    * @brief A two-dimensional vector representing the grid of tiles in the room.
    *
    * Each element in the grid is a pointer to a `Tile` object, which can either be a non-entity tile (e.g., wall, grass)
    * or a tile that contains an entity (e.g., enemy, item, player). */
    std::array<std::array <Tile*, 20>, 20> m_tileField;

    /**
    * @brief Assigns entities to the corresponding tiles in the room.
    *
    * This function iterates over the tile grid and assigns entities (enemies, items) to the appropriate tiles
    * based on the tile type. The entity manager is used to fetch references to the specific entities. */
    void assignEntitiesToTiles();
};



