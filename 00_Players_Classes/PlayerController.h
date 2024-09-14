#pragma once
#include "../04_Structs/PositionStruct.h"
#include "Player.h"
#include "../03_Map/Room.h"


/**
 * @class PlayerController.
 * @brief Manages player's movement and interactions within the room.
 *
 * The PlayerController class handles the movement of the player, including determining valid moves,
 * updating the player's position on the map, and managing interactions with entities such as items,
 * NPCs, and enemies. It also manages transitions between different rooms.
 */
class PlayerController {
private:
    /**
    * @brief Holds the direction of player movement to nextPosition.
    *
    * The direction is represented by a character:
    * - 'W' for up
    * - 'A' for left
    * - 'S' for down
    * - 'D' for right */
	char m_direction;

    /**
    * @brief Stores the player's previous position.
    *
    * This `Position` struct represents the player's coordinates in the room
    * before any movement occurs. */
	Position m_playerOldPosition;

    /**
    * @brief Stores the player's next position.
    *
    * This `Position` struct represents the player's new coordinates after performing movement
    * with certain direction ('W', 'A', 'S', 'D')*/
	Position m_playerNextPosition;

    /**
    * @brief Points to the current room where the player is located.
    *
    * This pointer references the `Room` object in which the player is present.
    * It is used to access the tile field and determine the player's current or next position
    * based on the room's layout. */
	Room* m_actualRoom;

    /**
    * @brief A pointer to the player object being controlled.
    *
    * This points to the `Player` instance and is used to access the player's attributes
    * and actions, such as health, inventory, or movement
    * --- Great question if it is really need it this way... PlayerController works with representation of player that is moving... */
	Player* m_player;

    /**
    * @brief Updates the player's old position to match the next position.
    *
    * This method saves this position as actual player position to which player moves on the tile field in the room.*/
	void updateControlsPosition();

    /**
    * @brief Removes the player's old position on tile.
    *
    * Sets the tile at the player's old position to a non-entity tile ('.'),
    * effectively "erasing" the player from last position.*/
    void removeOldPlayerPosition_onTF();

    /**
    * @brief Sets the player's next position tile.
    *
    * Marks the player's next position on the tile field by setting the corresponding tile
    * to represent the player ('P').*/
    void setNextPlayerPosition_onTF();

    /**
    * @brief Moves the player to the next position if it there is no wall or Enemy on that tile.
    *
    * If the tile is not Enemy or Wall ('.' or 'I'), the player will move to the new position.
    *
    * @param tileType The type of tile at the player's next position.*/
	void move(char tileType);

    /**
    * @brief Interacts with the tile entity at the next position.
    *
    * This function handles interactions with entities such as enemies ('E'), NPCs ('N'),
    * or items ('I') when the player encounters them at the next position.
    *
    * @param tileType The type of tile at the player's next position. */
	void interact(char tileType);

    /**
    * @brief Handles room transitions when the player reaches a travel tile.
    *
    * If the player moves onto a travel tile ('H' or 'O'), this function triggers a room transition.
    * If the TileType is 'O', player has option to move on specific location.
    * If the TileType is 'H', player has only option to return to "Home" - safe location.
    *
    * Player has option to rethink about travelling and decline to travel when he move onto travel tile
    *
    * @param tileType The type of tile the player is traveling to.
    * @param changeRoomYesOrNo Boolean flag to indicate a room change. */
    void travel(char tileType, bool& changeRoomYesOrNo);
public:
    /**
    * @brief Constructs a PlayerController object and sets initial player position and room.
    *
    * @param x Row position of the player in the room (st_x coordinate).
    * @param y Column position of the player in the room (st_y coordinate).
    * @param player Pointer to the Player object that this controller will manage.
    * @param room Pointer to the Room object where the player is located. */
    PlayerController(int x, int y, Player* player, Room* room);			// x = row	y = column

	/**
    * @brief Create the player's next position based on their current direction.
    *
    * The method first gets the player's old position (`getOldPosition()`) to `m_playerNextPosition` and
    * then modifies it based on the movement direction that was get in different method. The direction is provided as a character
    * ('W', 'A', 'S', 'D'), corresponding to movement.
    *
    * - 'W' (up): Decreases the X coordinate.
    * - 'S' (down): Increases the X coordinate.
    * - 'A' (left): Decreases the Y coordinate.
    * - 'D' (right): Increases the Y coordinate. */
	void createNextPosition();

    /**
    * @brief Processes the player's next position based on tile type and executes corresponding actions.
    *
    * This function analyzes the next position on the tile field where the player is attempting to move.
    * It determines if the player can move, interact, or travel to another room, and updates the game state accordingly.
    *
    * @param changeRoomYesOrNo - Boolean reference indicating if the player should change to a different room */
    void processNextPosition(bool& changeRoomYesOrNo);

    /**
    * @brief Gets the player's old position before movement.
    *
    * This function returns the previous position of the player within the room.
    *
    * @return Position struct containing the player's previous [x, y] coordinates. */
	Position getOldPosition() const;

    //Position getNextPosition();			bude se hodit pro portaly

    /**
    * @brief Gets the tile type at the player's next position.
    *
    * This function fetches the tile type from the room's tile field for the position where the player intends to move next.
    *
    * @return char representing the tile type at the player's next position. */
	char getTileType_nextPosition();

    /**
    * @brief Initializes the player's position on the map.
    *
    * Sets the player's initial position on the tile field when the game starts or
    * when the player enters a new room. */
    void setPlayerOnMap();

    /**
    * @brief Sets the player's movement direction based on the input key.
    *
    * @note The key is assumed to be validated before calling this function.
    *
    * @param key The validated direction key ('W', 'A', 'S', 'D') */
	void setDirection(char key);
};

