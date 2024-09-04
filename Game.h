#pragma once
#include "00_Players_Classes/Player.h"
#include "00_Players_Classes/PlayerController.h"
#include "03_Map/Map.h"
#include "05_FrontEndClasses/ConsoleManager.h"
#include "01_Enums/ActionType.h"

//TODO ERRORLOG globalem nebo singletonem
///TODO InGame rename to Actions_m also find "InGameMenu" zmínky

    /**
    * @class Game
    * @brief Manages the core gameplay functionality.
    *
    * @section Basic Information
    * The Game class handles the initialization of game elements, manages the main game loop, and processes player actions.
    *
    * @section Key Responsibilities
    * Coordinates the game environment, including player interactions, inventory management, and game state.
    * - **Initialization**: Sets up the game environment by creating and initializing key elements
    *
    * - **Game Loop**: Manages the continuous loop of the game, processing player actions, updating the game state, and
    *   rendering the environment until the game is terminated.
    *
    * - **Action Handling**: Determines and executes actions based on player input, including player movement, menu navigation,
    *   and item interactions.
    *
    * - **Inventory Management**: Manages the player's inventory, including accessing items, using them, and discarding them.
    *
    * - **Game State Management**: Controls the game's continuation or termination based on player decisions and game events.
    *
    * The Game class acts as the main controller for game operations.*/

    class Game {
    private:
    /**
    * @brief The starting room index
    *
    * This constant represents the initial index of room where player starts in the game.*/
    const int START_ROOM = 0;

    /**
    * @brief The starting location index
    *
    * This constant represents the initial index of location where player starts in the game.*/
    const int START_LOCATION = 0;

    /**
    * @section Entity section: Entity
    *
    * This section describes the member variables that interact with essential entities
    * and play a crucial role in managing the game's state and functionality
    */
    /**
    * @brief Pointer to the player object
    *
    * This pointer refers to the current player instance, which is central to the game's progression.
    * Also there are no other players - only this one.*/
    Player* m_player;

    /**
    * @brief Pointer to the map object
    *
    * This pointer refers to the map instance, which defines the game's world and its layout.
    * For a detailed explanation of how the map is structured and its attributes, please refer to the Map class documentation.
    */
    Map* m_map;

    /**
    * @brief Pointer to the current room object
    *
    * This pointer refers to the room where the player is currently located. */
    Room* m_actualRoom;

    /**
    * @brief Pointer to the PlayerController object managing player representation in the Room
    *
    * This pointer refers to the `PlayerController` class, which manages the representation of player's position and
    * updates his representation within a tile-based room.
    *
    * For detailed information, refer to the `PlayerController` class documentation.*/
    PlayerController* m_playerController;

    /**
    * @brief Flag indicating if the game is ongoing
    *
    * This boolean variable tracks whether the game should continue running. It is used to determine
    * if the game should keep playing or stop, based on player status or game exit decisions.
    *
    * The variable is directly manipulated and passed to functions to control the game flow.*/
    bool m_gameOngoing;

    /**
    * @brief Creates and initializes the game map
    *
    * This function creates a new instance of the `Map` class and assigns it to the `m_map` member variable.
    * The `Map` instance is initialized using the specified name of File ("filename"), which provides the
    * necessary data for map layout.
    *
    * @param filename The name of the file containing the map data.*/
    void createMap(std::string filename);

    /**
    * @brief Configures the cursor for room to be hidden.
    *
    * This method sets the cursor to an appropriate position for printing the room tile field that start from position [0, 0]
    * and then makes the cursor invisible because its visibility is not needed while display room.
    */
    void setCursor();

    /**
    * @brief Determines the action type based on player input.
    *
    * This method reads player input from the console and decides what action to perform based on the input.
    * It handles movement commands (W, A, S, D), game menu access (TAB), and game termination (ESC).
    * The action is determined as follows:
    * - **Movement**: If the input is W, A, S, or D, it sets the player's direction and returns `ActionType::Movement`.
    * - **In-Game Menu**: If the input is TAB, it returns `ActionType::InGameMenu`.
    * - **Quit Game**: If the input is ESC (27), it returns `ActionType::QuitGame`.
    *
    * @return The type of action to be performed based on the player input.*/
    ActionType decideActionType();

    /**
    * @brief Executes an action based on the provided action type.
    *
    * This function performs the appropriate action based on the `ActionType` value returned by `decideActionType`.
    * It handles three main types of actions:
    *
    * - **Movement**:
    *   - Creates a new position of player representation based on the previous input.
    *   - Analyzes and performs the action for the new position - if it is possible or not. The movement could not be performed for example if player try to move into the wall.
    *   - If the player tries to move to a different room (indicated by `changeRoomYesOrNo`), additional actions such as displaying a travel menu will be displayed and user has to select an option to travel somewhere or cancel the travel action
    *
    * - **Game Menu**:
    *   - Makes the text and cursor visible for the menu.
    *   - Displays the game menu and allows the player to navigate in this menu.
    *   - Executes the selected menu option by player by method `executeInGameMenuOption`, which can also affect the ongoing state of the game.
    *   - For a detailed explanation of `executeInGameMenuOption`, refer to its documentation in the Game class.
    *
    * - **Quit Game**:
    *   - Sets `m_gameOngoing` to `false`, which will stop the main game loop - that ActionType is get if the player choose in Game munu to quit game.
    *
    * @param action - The type of action to perform is determined by method `decideActionType`.*/
    void performAction(ActionType action);

    /**
    * @brief Executes the selected option from the In-Game Menu.
    *
    * This function handles the execution of the option chosen by the player in the In-Game Menu.
    * Depending on the selected option, different actions are performed:
    *
    * - **Option 1 (Personal Stats)**:
    *   - Displays the player's personal stats.
    *
    * - **Option 2 (Inventory)**:
    *   - Calls `accessInventory()` to allow the player to manage their inventory.
    *
    * - **Option 3 (Exit Menu)**:
    *   - Exits the menu and resumes the game.
    *
    * - **Option 4 (Leave Game)**:
    *   - Terminates the game by setting `gameOngoing` to `false`.
    *
    * - **Default (Error Handling)**:
    *   - Prints an error message if an invalid option is selected.
    *
    * After performing the selected action, the screen is cleared to reflect the choice of the player.
    *
    * @param gameOngoing A reference to the `gameOngoing` flag */
    void executeInGameMenuOption(bool &gameOngoing);

    /**
    * @brief Executes the selected option from the Inventory Menu.
    *
    * This function manages the player's interactions within the Inventory Menu. Based on the selected option,
    * the function performs the following actions:
    *
    * - **Option 1**:
    *   - Allows the player to heal lost health by 50 points of health.
    *    - For a detailed explanation of how recovery of health works(drinkPotion(), please refer to the Inventory class documentation.
    *     (Implementation will be added soon)
    *
    * - **Option 2**:
    *   - Displays a list of items in the player's inventory.
    *   - Allows the player to navigate through the list and select an item.
    *   - If an item is selected (not the option to leave the inventory), it retrieves the selected item, displays its details,
    *     and then calls 'executeItemAction(Item* item, int ItemIndex)' to perform further actions with the item.
    *
    * - **Option 3**:
    *   - Executes "Leave Inventory" and then the room representation will be shown again.
    *
    * After executing the chosen action, the screen is cleared, and the display is updated based on the player's choice.
    *
    * @note The implementation of Option 1 (drink health potion) is currently a placeholder and should be completed.
    */
    void executeInventoryOption();

    /**
    * @brief Executes an action on the selected item from the player's inventory.
    *
    * Based on the player's choice, this function performs specific actions with the selected item.
    *
    * - **Option 1**:
    *   - If the item is a Potion, the player consumes it.
    *   - If the item is Armor or a Weapon, the player equips / unequips it.
    *
    * - **Option 2**:
    *   - The selected item is discarded from the inventory using and deleted from program.
    *
    * - **Option 3**:
    *   - Returns to the inventory and display all items again allowing the player to choose another item or leave the inventory.
    *   - Will be implemented - right now it does nothing
    *
    * After the chosen action is executed, the screen is cleared and the appropriate interface is displayed.
    *
    * @param item Pointer to the item selected by the player.
    * @param itemIndex Index of the item in the player's inventory.*/
    void executeItemAction(Item* item, int itemIndex);

    /**
    * @brief Accesses the player's inventory and initiates the inventory management process.
    *
    * This method call for retrieving the total number of potions the player has and pass it on the method that displays the inventory menu.
    * After displaying the inventory menu, it allows the user to choose an action by calling
    * the `executeInventoryOption` method.
    *
    * @see executeInventoryOption() for handling specific inventory actions.
    */
    void accessInventory();

public:
    /**
    * @brief Default constructor for the Game class.
    *
    * This constructor initializes a new instance of the `Game` class with its attributes.
    * Inicialiaze the Pointer to object to nullptr (pointer will be added in method `setGameElements()` and mGameOngoing to true.
    */
	Game();

    /**
    * @brief Configures the game elements.
    *
    * This method initializes various game components, including setting the console output to UTF-8,
    * creating the player with its inner pointer to objects, map, setting the initial room, controls of movement and action of representation of player
    * and finally configuring the cursor for print of actual room where player starts.
    */
	void setGameElements();

    /**
    * @brief The main game loop that controls the game's flow.
    *
    * This function continuously runs the game loop as long as the player has health and the game is ongoing.
    * It performs the following steps in each iteration:
    * - Prints the current room using `ConsoleManager::printRoom`.
    * - Determines the action type based on user input and performs the corresponding action.
    * - Resets the cursor for printing the actual room after each action.
    * - Checks if the game should continue; if `m_gameOngoing` is false, the loop will eventually stop.
    * - Reprints the room after each action if the game has not ended because player died still ongoing.
    */
	void gameLoop();
	void testFunction(); 	// method for testing - it is not important and will be deleted
};

