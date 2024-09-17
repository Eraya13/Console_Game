#ifndef VIEW_H
#define VIEW_H
#include <vector>

#include "../02_Entity/Item.h"
#include "../02_Entity/Armor.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Potion.h"

/**
 * @class View
 * @brief Handles the display of various game-related information to the player.
 *
 * This frontend class is responsible for rendering text-based information on the console,
 * such as menus, item descriptions and confirmation messages. */
class View
{ 
private:
    /**
    * @brief Displays equip options for a weapon.
    * @param weapon Pointer to the Weapon object to display equip options.
    *
    * Shows whether the weapon can be equipped or unequipped based on its current equipped status. */
    static void EquipOption(Weapon* weapon);

    /**
    * @brief Displays equip options for armor.
    * @param armor Pointer to the Armor object to display equip options.
    *
    * Shows whether the armor can be equipped or unequipped based on its current equipped status. */
    static void EquipOption(Armor* armor);

    /**
    * @brief Displays information how to make an selection */
    static void howToSelect();
public:
    /**
    * @brief Displays a confirmation message for discarding an item. */
    static void discardConfirmationMessage();

    /**
    * @brief Displays the in-game menu options.
    *
    * This method outputs the game menu to the console, showing options such as viewing personal stats, inventory, exiting the menu, or leaving the game.
    * It also calls the `howToSelect()` method to inform the player on how to navigate the menu. */
    static void gameMenu();

    /**
    * @brief Displays a message when a weapon is equipped.
    *
    * This method shows a message to the console about what weapon has been equipped and about how strong player is now after equipping the weapon.
    *
    * @param weapon Pointer to the `Weapon` that has been equipped.
    * @param totalAttack The player's total attack power after equipping the weapon.*/
    static void equipmentInfo(Weapon* weapon, int totalAttack);

    /**
    * @brief Displays a message when armor is equipped.
    *
    * This method shows a message to the console about what armon has been equipped and about how much player is protected now after equipping the armor.
    *
    * @param armor Pointer to the `Armor` that has been equipped.
    * @param totalDefense The player's total defense after equipping the armor. */
    static void equipmentInfo(Armor* armor, int totalDefense);

    /**
    * @brief Displays all items in the inventory, including their type, name, and bonus information.
    * @param items A vector of pointers to Item objects to be listed. */
    static void inventoryItems(std::vector<Item*> items);

    /**
    * @brief Displays the inventory menu.
    * @param totalPotions The number of HP potions in the player's inventory.
    *
    * Shows the number of HP potions and these options: to drink a potion, display all items, or leave the inventory. */
    static void inventoryMenu(int totalPotions);
    
    /**
    * @brief Displays detailed information about a specific item.
    * @param item Pointer to the Item object to display.
    *
    * Shows details about the item, including its name, category, and specific attributes based on its type. */
    static void itemInfo(Item* item);

    /**
    * @brief Displays actions that can be performed on a specific item.
    * @param item Pointer to the Item object for which actions are displayed.
    *
    * Shows options for using, equipping, unequipping, or discarding the item, depending on its type. */
    static void itemActions(Item* item);

    /**
    * @brief Displays the game instructions to the player.
    *
    * This method outputs detailed instructions for playing the game to the console. It covers the following topics:
    * - Movement controls using W, A, S, D keys.
    * - How to access and navigate the game menu using [Tab], W, A, S, D keys, and [Enter].
    * - Instructions for exiting the game using [Esc].
    * - Information about game menu options such as viewing personal stats, inventory, and quitting the game.
    * - Health and game over conditions.
    * - The player's starting equipment (basic armor and no weapon). */
    static void gameInstructions();

    /**
    * @brief Displays a message indicating no potions are left in the inventory.
    *
    * This method outputs a message to the console informing the player that there are no potions left in the inventory, and thus nothing to drink. */
    static void noPotionLeft();

    /**
    * @brief Displays personal stats of the player.
    *
    * Shows detailed information about the player's stats, equipped armor, and weapon. */
    static void playerStats();
};

#endif // VIEW_H
