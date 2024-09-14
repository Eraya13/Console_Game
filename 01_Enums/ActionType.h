#pragma once

    /**
    * @enum ActionType
    * @brief Defines the types of actions that can perfom player in the game.
    *
    * This enumeration represents the different types of actions a player can take within in the room.
    *
    * - **Movement**: Represents player movement actions.
    * - **InGameMenu**: Represents interaction with the in-game menu.
    * - **QuitGame**: Represents the action to exit or quit the game.
    * - **Help**: Represents the information about how to control the game.
    */
enum class ActionType {
    Movement,     ///< Player movement actions
    InGameMenu,   ///< Interactions with the in-game menu
    QuitGame,      ///< Action to exit or quit the game
    Help          ///< Info about how to control the game
};
