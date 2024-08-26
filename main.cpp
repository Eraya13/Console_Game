#include <iostream>
#include "Map.h"
#include "Game.h"


int main() {
    // Get the current working directory
    //std::filesystem::path currentPath = std::filesystem::current_path();
    //std::cout << "Current working directory: " << currentPath << std::endl;
    
    Game* hra = new Game();
    hra->setGameElements();
    hra->gameLoop();
    
    
    /*IEntity* entity;
    entity = new Enemy("Derrien", 20, 10, 100, 454);
    entity->printInfo();
    */
    //Map* mapa = new Map("LocationsNames.txt");
    
    //delete mapa;
    return 0;
}
