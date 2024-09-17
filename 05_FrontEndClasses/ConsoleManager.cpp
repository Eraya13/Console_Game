#include "ConsoleManager.h"

// initiation of static member variables
CONSOLE_CURSOR_INFO ConsoleManager::cursorInfo = { 0 };
COORD ConsoleManager::cursorPos = { 0, 0 };     // defaul position for printRoom()
const int ConsoleManager::BACKGROUND = 16;
short ConsoleManager::m_cursorMax = 0;
short ConsoleManager::m_cursorMin = 0;

void ConsoleManager::setCursorForRoomPrint() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = { 0, 0 };
    SetConsoleCursorPosition(hConsole, {cursorPos.X, cursorPos.Y});
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

// Cursor Navigation private functions
void ConsoleManager::setCursorPosForMenu() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cursorPos = { 0, m_cursorMin };
    SetConsoleCursorPosition(hConsole, cursorPos);
}

void ConsoleManager::setCursorRange(int short const startPositon, int short const totalOptions) {
    m_cursorMin = startPositon;
    m_cursorMax = startPositon + totalOptions - 1;
}

void ConsoleManager::setCursorPosition() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //std::cout << "Kurzorr Y: " << cursorPos.Y << std::endl; - debug print
    SetConsoleCursorPosition(hConsole, cursorPos);
}

COORD ConsoleManager::getConsoleCursorPosition(HANDLE hConsole) {
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

void ConsoleManager::cursorNavigation(int short const start_position, int short const total_options){
    setCursorRange(start_position, total_options);
    setCursorPosForMenu();
    changeCursorPos();
}

int short ConsoleManager::getOptionIndex() {
    return cursorPos.Y - m_cursorMin + 1;
}

//----------**GUI & Main Print (PrintRoom)----------**
char ConsoleManager::readUserInput() {
    //std::cout << "Ctu zmacknuti tlacitka: \n";      // debug print
    char input = toupper(_getch());          
    return input;
}

void ConsoleManager::setColorTile(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND * color);    // sets required color for the space character
    printf(" ");    // print of space character
}

void ConsoleManager::setTextVisible() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,(int)Colors::White);   // sets text to white color
}

std::array<std::array<char, 40>, 20> ConsoleManager::AdjustTileFieldToSquareAspect(Room* actualRoom) {
    std::array<std::array <Tile*, 20>, 20> realTileField = actualRoom-> m_tileField;
    std::array<std::array <char, 40>, 20> virtualTileField;
    for (int row = 0; row < virtualTileField.size(); row++) {      // 0 - 19 row
        std::array <char, 40> tileRow;
        for (int column = 0; column < virtualTileField.size(); column++) {     // 0 - 39 column
            virtualTileField.at(row).at(2*column) = realTileField.at(row).at(column)->getTileType();
            virtualTileField.at(row).at((2*column) + 1) = realTileField.at(row).at(column)->getTileType();
        }
    }
    return virtualTileField;
}

void ConsoleManager::printRoom(std::array<std::array <char, 40>, 20> virtualTileField) {
    char tileType;
    for (int row = 0; row < virtualTileField.size(); row++) {
        for (int column = 0; column < virtualTileField.at(row).size(); column++) {
            char tileType = virtualTileField.at(row).at(column);
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
