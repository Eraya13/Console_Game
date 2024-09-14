#pragma once
    /**
    * @enum TileType.
    * @brief Represents different types of tiles in the game.
    *
    * This enum class defines various tile types that represent elements within a room.
    * Each tile type is associated with a specific character, which determines how it
    * should be displayed in the game and what it represents.
    * Each tile type is also associated with an appropriate color.
    *
    * Non-entity tiles:
    * - **GRASS**: Represented by '.' and displayed as a walkable area.
    * - **WALL**: Represented by '#' and displayed as an impassable barrier.
    * - **PORTAL**: Represented by 'O' and used to indicate a portal to another location.
    * - **HOME**: Represented by 'H' and indicates the player's home or a safe area.
    *
    * Entity tiles:
    * - **PLAYER**: Represented by 'P' and marks the player's position on the map.
    * - **ENEMY**: Represented by 'E' and marks an enemy position on the map.
    * - **ITEM**: Represented by 'I' and shows the presence of an item that can be picked up on the map. */
enum class TileType {
    
    GRASS = '.', ///< Walkable area
    WALL = '#',	 ///< Impassable barrier
    PORTAL = 'O', ///< Portal to another location
    HOME = 'H', ///< Player's home or safe area
    PLAYER = 'P', ///< Player's position
    ENEMY = 'E',  ///< Enemy's position
    ITEM = 'I',   ///< Item's position
};
