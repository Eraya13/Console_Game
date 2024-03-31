#include "GUI.h"

GUI::GUI() {}
// dodat parametr upscalu
void GUI::printRoom(Room* actualRoom) {
    std::array<std::array <Tile*, 20>, 20> printedRoom = actualRoom-> m_tileField;
    char tileType;
    for (int row = 0; row < printedRoom.size(); row++) {
        for (int column = 0; column < printedRoom.size(); column++) {
            char tileType = printedRoom.at(row).at(column)->getTileType(); // Toto je konkretni Tila!!!
            switch (tileType) {
                case '#': // WALL
                    setColorTile((int) Colors::Grey);
                    break;
                case '.': // FLOOR
                    setColorTile((int) Colors::LightWhite);
                    break;
                case 'I': // ITEM
                    setColorTile((int) Colors::Yellow);
                    break;
                case 'P': // PLAYER
                    setColorTile((int) Colors::Purple);
                    break;
                case 'E': // ENEMY
                    setColorTile((int) Colors::Red);
                    break;
                case 'N': // NPC
                    setColorTile((int) Colors::Green);
                    break;
                case 'O': // PORTAL
                case 'H': // HOME - Village
                    setColorTile((int) Colors::LightWhite);  
                    break;
            }
        }
        std::cout << std::endl;
    }
}

// Settings windows GUI
void GUI::setColorTile(int color) {
    SetConsoleTextAttribute(hConsole, BACKGROUND * color);    // nastavi se pozadovana barva pro "mezeru"
    printf(" ");
    SetConsoleTextAttribute(hConsole, BACKGROUND * (int)Colors::Black); // reset pozadi na cernou (pismena neobarvujeme)
}

void GUI::setDefaultCursorOnRoom() {
    // starting position - always the same!
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   cursorPos = {0, 0}; 
   SetConsoleCursorPosition(hConsole, {cursorPos.X, cursorPos.Y});
}

void GUI::toggleCursorVisibility() {
   GetConsoleCursorInfo(hConsole, &cursorInfo); // getting cursor info
   // this toggles cursor visibility - not sets true to false and vice versa
   cursorInfo.bVisible = not cursorInfo.bVisible;     
   SetConsoleCursorInfo(hConsole, &cursorInfo); // setting cursor info
}

// **********User input functions*******************
 char GUI::readInput_onMap() {
    std::cout << "Ctu zmacknuti tlacitka: \n";      // debug_print
    char input = toupper(_getch());          // WASD + tab + enter
    return input;
}