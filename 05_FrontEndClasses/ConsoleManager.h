#ifndef CONSOLEMANAGER_H
#define CONSOLEMANAGER_H
#include <windows.h>
#include <conio.h>
#include <vector>

#include "../02_Entity/Item.h"
#include "../02_Entity/Potion.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Armor.h"

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

    // **Tranformuje TileField 20x20 (row x column) na 20x40, aby roomka, aby každá tila tvořila čtverec při zobrazení
    // Tato funkce je potřeba jelikož příkazový řádek znak v poměru 2:1 (výška:šířka) - tzn. výška je dvojnásobná oproti šířce znaku
    static std::array<std::array <char, 40>, 20>  AdjustTileFieldToSquareAspect(Room* actualRoom);
    // Zobrazí Roomku jako TileField 20x40 - vypadá to mnohem lépe než 20x20 (obdelníkové prvky)
    static void printRoom(std::array<std::array <char, 40>, 20> virtualTileField);     // 40 columns : 20 rows
    static char readUserInput(); // cte input a vraci input

    // Cursor functions
    static void setCursorVisible();
    static void setCursorINvisible();
    static void setCursorForRoomPrint(); // set cursor for room print
    static void cursorNavigation(int short const def_position, int short const options);
    static int short getOptionIndex();
    // Print functions
    static void setColorTile(int color);
    static void setTextVisible(); // nastaví visibilitu textu pro "menu zobrazení" a zobrazení, když je skrytá mapa

    // Menus call for print
    static void displayInGameMenu();
    // **Provedení vybraných možností z menu
    // Zobrazení vybrané možnosti z InGameMenu na základě pozice kurzoru
    static void executeInGameMenuOption(bool &gameOngoing);
    static void executeInventoryMenuOption();
};

#endif // CONSOLEMANAGER_H
