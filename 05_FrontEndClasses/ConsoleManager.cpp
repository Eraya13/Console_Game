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

//*********** Navigation private functions:
void ConsoleManager::setCursorPosForMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = { 0, m_cursorMin };
    SetConsoleCursorPosition(hConsole, cursorPos);
}

void ConsoleManager::setCursorRange (int short const startPositon, int short const totalOptions) {
    m_cursorMin = startPositon;
    m_cursorMax = startPositon + totalOptions - 1;
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
        input = readUserInput();
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
void ConsoleManager::cursorNavigation (int short const start_position, int short const total_options){
    setCursorRange(start_position, total_options);
    setCursorPosForMenu();
    changeCursorPos();
}

//----------**GUI & Main Print (PrintRoom)----------**
char ConsoleManager::readUserInput() {
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

std::array<std::array <char, 40>, 20> ConsoleManager::AdjustTileFieldToSquareAspect(Room* actualRoom) {
    std::array<std::array <Tile*, 20>, 20> realTileField = actualRoom-> m_tileField;
    std::array<std::array <char, 40>, 20> virtualTileField;
    for (int row = 0; row < virtualTileField.size(); row++) {      // 0 - 20 řádek
        std::array <char, 40> tileRow;
        for (int column = 0; column < virtualTileField.size(); column++) {     // 0 - 39 sloupec
            virtualTileField.at(row).at(2*column) = realTileField.at(row).at(column)->getTileType();
            virtualTileField.at(row).at((2*column) + 1) = realTileField.at(row).at(column)->getTileType();
        }
    }
    return virtualTileField;
}

void ConsoleManager::printRoom(std::array<std::array <char, 40>, 20> virtualTileField) {
    char tileType;
    for (int row = 0; row < virtualTileField.size(); row++) {  // kolik má pole v sobě polí (tzn. řádků)
        //-- Pole řádků - řádek obsahuje sloupce = vnější se skládá z pole a pole z polí (pokud je) nebo z prvků
        for (int column = 0; column < virtualTileField.at(row).size(); column++) { // kolik má řádek prvků
            char tileType = virtualTileField.at(row).at(column); // Toto je konkretni Tila!!!
            // Vypíše se konkrétní Tile type - grafické zobrazení
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

void ConsoleManager::displayInventoryMenu() {
    View::Inventory_m();
}

// ------**Execution of Menus**------               // ZMĚNÍ SE: ZŮSTANE POUZE PERSONAL STATS, INVENTORY, EXIT MENU, LEAVE GAME
// **Provedení vybraných možností z InGameMenu
int short ConsoleManager::getOptionIndex() {
    return cursorPos.Y - m_cursorMin + 1;
}

void ConsoleManager::executeInGameMenuOption (bool &gameOngoing) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = getConsoleCursorPosition(hConsole);
    int option = getOptionIndex();      // převod indexu na možnost k provedení dle switche
    system ("cls");
    switch (option) {
    case 1:
        std::cout << "\nPersonal Stats\n" << std::endl;
        system ("pause");
        break;
    case 2:
        std::cout << "\nInventory\n" << std::endl;      // zde se zavolá View::DisplayInventory_m + navigationCursor + executeInventoryOption
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


void ConsoleManager::executeInventoryMenuOption() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = getConsoleCursorPosition(hConsole);
    int option = getOptionIndex();      // převod indexu na možnost k provedení dle switche
    system ("cls");
    switch (option) {
    case 1:
        break;
    case 2: {
        View::listInventoryItems();
        system("pause");
        break;
    }
    case 3:
        break;
    }
}
