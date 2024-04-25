#include "GUI.h"

GUI::GUI() {
    m_screen = new DisplayScreens();
}
// dodat parametr upscalu
/*std::array<std::array <Tile*, 20>, 20> GUI::upscaleMap(std::array<std::array <Tile*, 20>, 20>, int scale) {
}*/
//Note: upscaleMap se nasobi s tim, kde je kurzor, pokud budu mit dvojnasobnou velikosti nikoliv jen basic 1

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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND * color);    // nastavi se pozadovana barva pro "mezeru"
    printf(" ");
    SetConsoleTextAttribute(hConsole, BACKGROUND * (int)Colors::Black); // reset pozadi na cernou (pismena neobarvujeme)
}

// --------Cursor settings--------
// Visibility:¨
// tuto metodu zatim nepouzivam...
void GUI::toggleCursorVisibility() {
   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleCursorInfo(hConsole, &cursorInfo); // getting cursor info
   // this toggles cursor visibility - not sets true to false and vice versa
   cursorInfo.bVisible = not cursorInfo.bVisible;     
   SetConsoleCursorInfo(hConsole, &cursorInfo); // setting cursor info
}
// metody nize se pouzivaji!!!
void GUI::setCursorVisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void GUI::setCursorINvisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// ********** Set Cursor position ****************
// to do set enum value "map" + certain value for each type menu
void GUI::setDefaultCursorOnRoom() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = {0, 0}; // start position map
    SetConsoleCursorPosition(hConsole, {cursorPos.X, cursorPos.Y});
}

void GUI::setCursorStartPosition() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = { 0, m_cursorMin };
    SetConsoleCursorPosition(hConsole, cursorPos);
}

void GUI::setCursorPosition () {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos.X = 0;
    //std::cout << "Kurzorr Y: " << cursorPos.Y << std::endl;
    SetConsoleCursorPosition(hConsole, cursorPos);
}

// ********** Set Cursor other things ****************
void GUI::setCursorRange (int short const defaultPosition, int short const options) {
    m_cursorMin = defaultPosition;
    m_cursorMax = defaultPosition + options - 1;
}

COORD GUI::getConsoleCursorPosition (HANDLE hConsole) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    return csbi.dwCursorPosition;
}

void GUI::cursorNavigation (int short const def_position, int short const options){
    char input;
	// bude obecna promenna z Menu enum class
    setCursorRange(def_position, options);
    setCursorStartPosition();
    changeCursorPos();
}

// je to soucasti cursorNavigation - otestovat doma
void GUI::changeCursorPos() {
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

// Display PRINT
void GUI::displayInGameMenu() {
   m_screen->inGameMenu_m();
}

// Display Options:
void GUI::displayMenuOptions (bool &gameOngoing) {
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
            std::cout << "\nQuests\n" << std::endl;     // MISTO TOHO UDELAT DIARY!!!! (bude obsahovat celé konverzace or záznam, co uživatel dělal na mapě - logger)
            system ("pause");
            break;
        case 4: // Nic se nedeje - konec funkce
            std::cout << "\nExit Menu\n" << std::endl; // debug print
            system ("pause");
            break;
        case 5:
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

// **********User input functions*******************
 char GUI::readInput_onMap() {
    //std::cout << "Ctu zmacknuti tlacitka: \n";      // debug_print
    char input = toupper(_getch());          // WASD + tab + enter
    return input;
}