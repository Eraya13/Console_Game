#include "ConsoleManager.h"

ConsoleManager::ConsoleManager() {}

// inicializace statických proměnných
CONSOLE_CURSOR_INFO ConsoleManager::cursorInfo = { 0 }; // Inicializace struktury na nuly
COORD ConsoleManager::cursorPos = { 0, 0 }; // výchozí pozice pro printRoomky
const int ConsoleManager::BACKGROUND = 16; // Inicializace konstanty
short ConsoleManager::m_cursorMax = 0;
short ConsoleManager::m_cursorMin = 0;

// --------Cursor settings--------
void ConsoleManager::setCursorForRoomPrint() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, {cursorPos.X, cursorPos.Y}); // nastavení kurzoru na zadanou pozici
}

void ConsoleManager::setCursorINvisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void ConsoleManager::setCursorVisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}






//----------**GUI & Main Print (PrintRoom)----------**

// --------Colors settings--------
// Negativní důsledek: Pokud se pokusím zobrazit text - je zobrazet podle poslední vypsané tily (nehezký tedy)
// obarví tilu pro mapu dle typu tily a následně setne Konzoli na černou...
void ConsoleManager::setColorTile(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND * color);    // nastavi se pozadovana barva pro "mezeru"
    printf(" "); // print požadovanou barvou
}

// Text je opět viditelný - má být v případě, že dojde k cestování nebo menu zobrazení
// automaticky je zas neviditelný v případě provedení akce na mapě (znovunačtení roomky)
void ConsoleManager::setTextVisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,(int)Colors::White); // nastavi pismo na white
}

void ConsoleManager::printRoom(Room* actualRoom) {
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
