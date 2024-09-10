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
    /**
    * @brief Information about the console cursor's visibility and size.*/
    static CONSOLE_CURSOR_INFO cursorInfo;

    /**
    * @brief The current position of the cursor in the console. */
    static COORD cursorPos;

    /**
    * @brief Constant value representing the background color setting for the console. */
    static int const BACKGROUND;

    /**
    * @brief The maximum allowed Y-position for the cursor in menu navigation. */
    static int short m_cursorMax;     
    
    /**
    * @brief The minimum allowed Y-position for the cursor in menu navigation. */
    static int short m_cursorMin;

    /**
    * @brief Sets the cursor position for printing the room layout. */
    static COORD getConsoleCursorPosition (HANDLE hConsole);

    // interní funkce cursorNavigation()
    /**
    * @brief Sets the vertical range of the cursor for menu navigation.
    *
    * This function defines the vertical range within which the cursor can move when navigating
    * through the menu options. It ensures that the cursor remains within the specified range.
    *
    * @param defaultPosition The starting vertical position of the cursor.
    * @param options The total number of menu options available, which determines the end of the range. */
    static void setCursorRange(int short const defaultPosition, int short const options);

    /**
    * @brief Sets the starting position of the cursor for the menu.
    *
    * This function positions the cursor at the beginning of the menu, typically at the top of the
    * menu options, so that the user can start navigating from the correct position. */
    static void setCursorPosForMenu();

    /**
    * @brief Moves the cursor position up or down based on user input.
    *
    * This function adjusts the cursor's vertical position in response to user input. The cursor
    * moves up or down until the Enter key is pressed or the cursor reaches the specified range limits. */
    static void changeCursorPos();

    /**
    * @brief Sets the cursor to the specified position based on user input.
    *
    * This function positions the cursor at the exact location specified by the user input. It
    * ensures the cursor is placed at the correct position within the defined range for the menu. */
    static void setCursorPosition();
public:

    //ConsoleManager();
    /**
    * @brief Transforms a 20x20 Tile Field array into a 20x40 array to ensure each tile appears as a square.
    *
    * This function adjusts the aspect ratio of the room display, as console characters are displayed
    * with a 2:1 height-to-width ratio, meaning the height is twice the width of the characters.
    *
    * @param actualRoom Pointer to the room whose tile field needs to be adjusted.
    * @return A 20x40 array of characters representing the room with square tiles. */
    static std::array<std::array <char, 40>, 20>  AdjustTileFieldToSquareAspect(Room* actualRoom);

    /**
    * @brief Displays the room as a 20x40 Tile Field for better visual appearance compared to 20x20.
    *
    * This function prints a 20x40 matrix (40 columns, 20 rows) which gives a more aesthetically
    * pleasing view than a 20x20 matrix by avoiding rectangular elements.
    *
    * @param virtualTileField A 20x40 array of characters representing the room. */
    static void printRoom(std::array<std::array <char, 40>, 20> virtualTileField);
    
    /**
    * @brief Reads the user input and returns it.
    *
    * This function reads a single character from the user's input and returns it. It handles
    * both lowercase and uppercase inputs by converting all inputs to uppercase.
    *
    * @return The character input by the user, converted to uppercase. */
    static char readUserInput();

    /**
    * @brief Makes the console cursor visible. */
    static void setCursorVisible();

    /**
    * @brief Hides the console cursor from console view. */
    static void setCursorINvisible();

    /**
    * @brief Sets the cursor position for room printing.
    *
    * This function initializes the cursor position to the top-left corner of the console
    * for printing the room. */
    static void setCursorForRoomPrint(); // set cursor for room print
    
    /**
    * @brief Handles cursor navigation within a menu.
    *
    * This function allows the player to navigate through menu options using the cursor. The
    * navigation is bounded by the minimum and maximum cursor positions. The player can move
    * the cursor up and down and select an option by pressing Enter.
    *
    * @param def_position The initial cursor position.
    * @param options The total number of menu options available. */
    static void cursorNavigation(int short const def_position, int short const options);
    
    /**
    * @brief Gets the index of the currently selected menu option.
    *
    * This function calculates the index of the selected option based on the current cursor
    * position.
    *
    * @return The index of the selected menu option. */
    static int short getOptionIndex();
    
    /**
    * @brief Sets the color of the tile to be displayed.
    *
    * This function sets the color of the console text attribute to represent different tile
    * types in the room. It prints a space character that has set color.
    *
    * @param color The color code to be set for the tile. */
    static void setColorTile(int color);
    
    /**
    * @brief Sets the text visibility for menu display.
    *
    * This function makes the text visible for menu display or when the map is not displayed. The text
    * visibility is automatically managed when the map is reloaded. */
    static void setTextVisible();
    
    /**
    * @brief Executes the selected option from the in-game menu.
    *
    * This function performs the action associated with the selected menu option based on the
    * current cursor position. It updates the game state accordingly.
    *
    * @param gameOngoing A reference to a boolean indicating if the game is still ongoing. This
    *                    parameter is updated based on the selected menu option. */
    static void executeInGameMenuOption(bool &gameOngoing);

    /// WAIT THOSE EXECUTION WILL BE ONLY IN GAME!!!!
    /**
    * @brief Executes the selected option from the inventory menu.
    *
    * This function performs the action associated with the selected inventory menu option. */
    static void executeInventoryMenuOption();
};

#endif // CONSOLEMANAGER_H
