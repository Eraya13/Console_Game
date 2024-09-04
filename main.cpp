#include <iostream>
#include "Map.h"
#include "Game.h"
#include "02_Entity/Weapon.h"
#include "02_Entity/Item.h"
#include "02_Entity/Potion.h"
#include "02_Entity/Armor.h"
#include "00_Players_Classes/Inventory.h"

    /**
    * @brief The main entry point of the game application.
    *
    * This function initializes the game, sets up the necessary game elements,
    * and enters the main game loop.
    * @return int Returns 0 upon successful completion of the program.
    */

int main() {
    // Get the current working directory
    //std::filesystem::path currentPath = std::filesystem::current_path();
    //std::cout << "Current working directory: " << currentPath << std::endl;
    //Map* mapa = new Map("LocationsNames.txt");

    /// Initialize the game
    Game* game = new Game();

    // These functions are documented in the Game class. Please refer to the documentation there.
    game->setGameElements();
    game->gameLoop();
    
    /// Frees the memory allocated for the game object.
    delete game;
    //delete mapa;
    return 0;
}
