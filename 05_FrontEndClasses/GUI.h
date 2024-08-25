#pragma once
#include <windows.h>
#include <conio.h>

#include "../01_Enums/Colors.h"
#include "../03_Map/Room.h"
#include "DisplayScreens.h"

class GUI {
private:
    DisplayScreens* m_screen;
    // Cursor setting
        // varriables:
    CONSOLE_CURSOR_INFO cursorInfo;
    COORD cursorPos;
    int static const BACKGROUND = 16;
    int short m_cursorMax;  // range variable for MenuPrint
    int short m_cursorMin;
    void setColorTile(int color);
    void setCursorStartPosition();  // set start position cursor for menu
    void setCursorRange(int short const defaultPosition, int short const options); // nastavi range cursoru pro cteni menu
    void changeCursorPos();
    void setCursorPosition();       // set cursor podle inputu playera (uvnitr menu)
public:
    GUI();
     // graphics:
    //std::array<std::array <Tile*, 20>, 20> upscaleMap(std::array<std::array <Tile*, 20>, 20>, int scale);
    void printRoom(Room* actualRoom);
    char readInput_onMap(); // cte input a vraci input
    // Gettery:
    COORD getConsoleCursorPosition(HANDLE hConsole);
    // Settery visibility Cursor
    void toggleCursorVisibility();
    void setCursorVisible();
    void setCursorINvisible();
    // Settery Cursor Position
    void setDefaultCursorOnRoom(); // set cursor for room print
    void cursorNavigation(int short const def_position, int short const options);
   // Menus
    void displayInGameMenu(); 
    void displayMenuOptions (bool &gameOngoing);
};
