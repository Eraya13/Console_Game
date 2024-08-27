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
    cursorPos = { 0, 0 };
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

// Navigation private functions:
void ConsoleManager::setCursorPosForMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = { 0, m_cursorMin };
    SetConsoleCursorPosition(hConsole, cursorPos);
}

void ConsoleManager::setCursorRange (int short const defaultPosition, int short const options) {
    m_cursorMin = defaultPosition;
    m_cursorMax = defaultPosition + options - 1;
}

void ConsoleManager::setCursorPosition () {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //std::cout << "Kurzorr Y: " << cursorPos.Y << std::endl;
    SetConsoleCursorPosition(hConsole, cursorPos);
}

// getne současný kurzor pro určení optiony na základě pozice pod mapou
COORD ConsoleManager::getConsoleCursorPosition (HANDLE hConsole) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    return csbi.dwCursorPosition;
}

void ConsoleManager::changeCursorPos() {
    int input;
    do {
        input = readInput_onMap();
        switch (input) {
        case 'W':
            cursorPos.Y--;
            break;
        case 'S':
            cursorPos.Y++;
            break;
        }
        if (cursorPos.Y > m_cursorMax) {
            cursorPos.Y--;
        }
        else if (cursorPos.Y < m_cursorMin) {
            cursorPos.Y++;
        }
        setCursorPosition();
    } while (input!= '\r');
}

// spustí se navigace kurzoru - tzn. hráč si může přesouvat kurzor a když zmáčkne enter vše skončí (něco si vybere)
void ConsoleManager::cursorNavigation (int short const def_position, int short const options){
    setCursorRange(def_position, options);
    setCursorPosForMenu();
    changeCursorPos();
}

//----------**GUI & Main Print (PrintRoom)----------**
char ConsoleManager::readInput_onMap() {
    //std::cout << "Ctu zmacknuti tlacitka: \n";      // debug_print
    char input = toupper(_getch());          // WASD + tab + enter
    return input;
}

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

// dodat parametr upscalu
/*std::array<std::array <Tile*, 20>, 20> GUI::upscaleMap(std::array<std::array <Tile*, 20>, 20>, int scale) {
}*/
//Note: upscaleMap se nasobi s tim, kde je kurzor, pokud budu mit dvojnasobnou velikosti nikoliv jen basic 1

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

// ------**DisplayPrints**------
void ConsoleManager::displayInGameMenu() {
    View::inGameMenu_m();
}

// ------**Execution of Menus**------               // ZMĚNÍ SE: ZŮSTANE POUZE PERSONAL STATS, INVENTORY, EXIT MENU, LEAVE GAME
// **Provedení vybraných možností z InGameMenu
void ConsoleManager::executeInGameMenuOption (bool &gameOngoing) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = getConsoleCursorPosition(hConsole);
    // uprava cursorPos.Y
    int option = cursorPos.Y - (int short) 1 - (int short) 20; // Menu::Menu_startPos
    system ("cls");				// mozna bu
    switch (option) {
    case 1:
        std::cout << "\nPersonal Stats\n" << std::endl;
        system ("pause");
        break;
    case 2:
        std::cout << "\nInventory\n" << std::endl;
        system ("pause");
        break;
    case 3:
        std::cout << "\nExit Menu\n"  << std::endl;
        system ("pause");
        break;
    case 4: // Nic se nedeje - konec funkce
        std::cout << "\nLeave Game\n" << std::endl; // debug print
        gameOngoing = false;
        system ("pause");
        break;
    default:
        std::cout << "\nError - no option found\n" << std::endl; // todo ErorLog
        system ("pause");
    }
    system ("cls");
}
