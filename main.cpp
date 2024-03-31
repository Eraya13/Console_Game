#include <iostream>
#include <fstream>
#include <filesystem>
#include "Game.h"

int main() {
    // Get the current working directory
    //std::filesystem::path currentPath = std::filesystem::current_path();
    //std::cout << "Current working directory: " << currentPath << std::endl;
    Game* hra = new Game();
    hra->setGameElements();
    //hra->testFunction();
    hra->gameLoop();
    return 0;
}