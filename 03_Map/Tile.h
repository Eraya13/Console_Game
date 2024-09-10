#pragma once
#include "../01_Enums/TileType.h"
#include "../02_Entity/Enemy.h"

/**
 * @brief Represents a tile in the room.
 *
 * Each Tile object can hold an entity (or be empty - nullptr). Entities are represented by a pointer to `IEntity`.
 * If the pointer is `nullptr`, the tile is considered empty. Otherwise, the tile contains an entity.
 * 
 * Currently, entity interactions are simulated based on the tile type (`m_tileType`), but the actual
 * management of entities (adding, removing, interacting) is not yet fully implemented.*/
class Tile {
private:
    /**
    * @brief Represents the type of tile on the map.
    *
    * This attribute indicates the type of entity or feature that occupies a specific tile in the room.
    * The value of `m_tileType` determines what is on the tile and therefore what interactions are possible.
    *
    * Tile types include:
    * - **Entity Tiles:** `E` = Enemy, `I` = Item, `P` = Player
    * - **Non-Entity Tiles:** `#` = Wall, `.` = Empty space (Grass)
    * - **Travel Tiles:** `O` = Portal, `H` = Home */
    char m_tileType;

    /**
    * @brief Pointer to an entity present on the tile.
    *
    * This attribute holds a pointer to an `IEntity` object that represents the entity occupying the tile.
    * Depending on the tile type, this entity can be of any child derived from `IEntity`, including:
    * - `P` = Player
    * - `E` = Enemy
    * - `I` = Item
    *
    * This allows the tile to store a reference to an entity, regardless of its specific type. */
    IEntity* m_entity;			// Tile obsahuje 1 Entity if E, I				// jsem si vedoma redunance, ze #, ., O, H - nepotřebují atribut m_entity...
public:
    /**
    * @brief Constructor for Tile that sets its type.
    *
    * Initializes a tile with a specified type and sets the entity pointer to `nullptr`.
    * Future Implementation - it will inialize with certain entity or it will be set afterwards...
    * @param type Character representing the type of the tile (e.g., Wall, Player, Empty Space).*/
	Tile(char tile);
    /**
    * @brief Retrieves the type of the tile.
    *
    * @return The tile type as a char. */
	char getTileType() const;

    /**
    * @brief Sets the type of the tile to a new one.
    *
    * Changes the tile type to the provided new type.
    *
    * @param newType The new type for the tile.*/
	void setTileType(char newType);

    /**
    * @brief Sets the entity occupying the tile.
    *
    * Assigns an entity to the tile if the entity is `nullptr`. If it is not `nullptr`, an error message is printed.
    *
    * @param entity A pointer to the entity to set on the tile. */
	void setTileEntity(IEntity *entity);			
    /**
    * @brief Empties the entity from the tile.
    *
    * Sets the entity pointer on the tile to `nullptr`, effectively removing any entity occupying the tile. */
    void emptyTileEntity();

    /// Will be implemented
    Enemy* castEnemy();
	//Entity castItem();
};

