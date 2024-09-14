#pragma once

/**
 * @struct Position
 * @brief A structure representing the player's position on a specific tile within a room.
 * 
 * This helper structure is used to store and pass the player's current position within the room, 
 * specifying the exact tile in the room on which the player stands or will move to. It is primarily used 
 * by the PlayerController to manage player movement. */
struct Position {
	int st_x; ///< X coordinate of the player's position on the tile
	int st_y; ///< Y coordinate of the player's position on the tile
};
