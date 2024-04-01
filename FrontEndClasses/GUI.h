#pragma once
#include <iostream>
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
    HANDLE hConsole;
    COORD cursorPos;
    int static const BACKGROUND = 16;
    void setColorTile(int color);
public:
    GUI();
     // graphics:
    std::array<std::array <Tile*, 20>, 20> upscaleMap(std::array<std::array <Tile*, 20>, 20>, int scale);
    void printRoom(Room* actualRoom);
    void displayInGameMenu();

    // GUI
    void setCursorPosition(int short x, int short y);
    void setCursorPosition(); //    default for most menus
    char readInput_onMap(); // cte input a vraci input
    void setCursorForMenuPrint();
    void setCursorRange(int range);
    void setDefaultCursorOnRoom(); // sklada se z volani funkci windows.h
    void toggleCursorVisibility();
    void setCursorVisible();
    void setCursorINvisible();

};