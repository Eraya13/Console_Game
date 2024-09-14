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
    static void toEquipOption(Weapon* weapon);
     
    /**
    * @brief Displays equip options for armor.
    * @param armor Pointer to the Armor object to display equip options.
    *
    * Shows whether the armor can be equipped or unequipped based on its current equipped status. */
    static void toEquipOption(Armor* armor);
     
    /**
    * @brief Displays information how to make an selection */
    static void howToSelect();
public:
    /**
    * @brief Shows a confirmation message for discarding an item. */
    static void showDiscardConfirmationMessage();

    static void inGameMenu_m();

    /**
    * @brief Displays all items in the inventory, including their type, name, and bonus information.
    * @param items A vector of pointers to Item objects to be listed. */
    static void listInventoryItems(std::vector<Item*> items);

    /**
    * @brief Displays the inventory menu.
    * @param totalPotions The number of HP potions in the player's inventory.
    *
    * Shows the number of HP potions and these options: to drink a potion, display all items, or leave the inventory. */
    static void displayInventory_m(int totalPotions);
    
    /**
    * @brief Displays detailed information about a specific item.
    * @param item Pointer to the Item object to display.
    *
    * Shows details about the item, including its name, category, and specific attributes based on its type. */
    static void displayItemInfo(Item* item);

    /**
    * @brief Displays actions that can be performed on a specific item.
    * @param item Pointer to the Item object for which actions are displayed.
    *
    * Shows options for using, equipping, unequipping, or discarding the item, depending on its type. */
    static void displayItemActions(Item* item);

    static void displayGameInstructions();

    /**
    * @brief Displays personal stats of the player.
    *
    * Shows detailed information about the player's stats, equipped armor, and weapon. */
    static void playerStats();
};

// todo -> rename: InGameMenu_m -> displayGameMenu()
// listInventoryItems(std::vector<Item*> items) -> displayInventoryItems(std::vector<Item*> items) 
// toEquipOption --> displayEquipOption()
// playerStats --> displayPlayerStats()


#endif // VIEW_H
