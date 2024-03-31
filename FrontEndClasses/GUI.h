#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "../01_Enums/Colors.h"
#include "../03_Map/Room.h"

class GUI {
	private:
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
    void printRoom(Room* actualRoom);
    // GUI
    char readInput_onMap(); // cte input a vraci input
    void setCursorForMenuPrint();
    void setCursorRange(int range);
    void setDefaultCursorOnRoom(); // sklada se z volani funkci windows.h
    void toggleCursorVisibility();
};