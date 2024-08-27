#ifndef CONSOLEMANAGER_H
#define CONSOLEMANAGER_H
#include <windows.h>
#include <conio.h>

#include "View.h"
#include "../01_Enums/Colors.h"
#include "../03_Map/Room.h"

class ConsoleManager
{
private:
    // Cursor variables
    static CONSOLE_CURSOR_INFO cursorInfo;
    static COORD cursorPos;
    static int const BACKGROUND;
    static int short m_cursorMax;  // range variable for MenuPrint
    static int short m_cursorMin;

    // Cursor functions
    static COORD getConsoleCursorPosition (HANDLE hConsole);
    // interní funkce cursorNavigation()
    static void setCursorRange(int short const defaultPosition, int short const options); // nastavi vertikální range cursoru, v kterém se může pohybovat pro cteni menu
    static void setCursorPosForMenu();  // set start position cursor for menu
    static void changeCursorPos();         // posune pozici kurzoru nahoru či dolů - dokud není zadán enter a nejedná se o pozici mimo range
    static void setCursorPosition();       // nastaví onu pozici od usera v changeCursorRoom
public:
    ConsoleManager(); // nevyužiju
    // GUI & Main Print (PrintRoom)
    static void printRoom(Room* actualRoom);
    static char readInput_onMap(); // cte input a vraci input

    // Cursor functions
    static void setCursorVisible();
    static void setCursorINvisible();
    static void setCursorForRoomPrint(); // set cursor for room print
    static void cursorNavigation(int short const def_position, int short const options);
    // Print functions
    static void setColorTile(int color);
    static void setTextVisible(); // nastaví visibilitu textu pro "menu zobrazení" a zobrazení, když je skrytá mapa

    // Menus call for print
    static void displayInGameMenu();

    // **Provedení vybraných možností z menu
    // Zobrazení vybrané možnosti z InGameMenu na základě pozice kurzoru
    static void executeInGameMenuOption(bool &gameOngoing);

};

#endif // CONSOLEMANAGER_H
