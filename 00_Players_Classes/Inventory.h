#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>

#include "../02_Entity/Item.h"
#include "../02_Entity/Armor.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Potion.h"

/**
 * @class Inventory
 * @brief Manages a collection of items for a player.
 *
 * The `Inventory` class is responsible for handling a player's collection of items in a game. It manages addition, discard, finding and getting the list or certain item. The inventory keeps track of all collected items and provides functionality to manage them.
 *
 * The `Inventory` class is responsible for handling a player's collection of items in a game. The main functions of this class include storing items, returning pointers to items, and managing their existence (e.g., adding and discarding items).*/
class Inventory
{
private:
    //int m_coins;

    /**
    * @brief A vector that stores pointers to items in the inventory
    *
    * This container holds all the items that player has collected.
    * Each item is represented by a pointer to `Item` object.*/
    std::vector<Item*> m_items;

    /**
    * @brief The total number of items in the inventory
    *
    * This member variable tracks the total count of items currently stored
    * in the player's inventory.*/
    int m_totalNumberItems;
public:
    /**
    * @brief Constructs a new `Inventory` object
    *
    * This constructor initializes the inventory preparing it to store items.*/
    Inventory();

    /**
    * @brief Destroys the `Inventory` object
    *
    * This destructor cleans up any items that has been allocated in the inventory. */
    ~Inventory();
    
    /**
    * @brief Adds an item to the inventory
    *
    * This function takes a pointer to an `Item` object and adds it to the inventory.
    * It also increments the total number of items in the inventory.
    *
    * @param item - A pointer to the `Item` to be added to the inventory*/
    void addItem(Item* item);

    /**
    * @brief Removes an item from the inventory and deallocates its memory.
    *
    * This method removes an `Item` from the inventory based on its index, deletes the item to free up memory,
    * and decrements the total number of items in the inventory. If the provided index is invalid, an error message is displayed.
    *
    * @param item - A pointer to the `Item` to be removed and deleted.
    * @param itemIndex - A index of the `Item` that should be removed from m_items container. */
    void discardItem(Item* item, int itemIndex);

    /**
    * @brief Finds the first potion in the inventory.
    *
    * This method searches the inventory for the first item categorized as a "Potion".
    * If potion is found, it sets the `potion` pointer to potion item and updates the `index` to
    * the position of the potion in the inventory (`m_items`). If no potion is found, `potion` remains `nullptr` and
    * `index` is set to -1.
    * The potion found is used by the player to restore health in function drinkPotion.
    * @param[out] potion - reference to a pointer to the potion found, or `nullptr` if no potion is available.
    * @param[out] index - index of the found potion in the inventory, or -1 if no potion is found.
    */
    void findPotion(Item*& potion, int& index);

    /**
    * @brief Returns the number of potions in the inventory
    *
    * This function iterates through the inventory items and counts how many of them are categorized as "Potion".
    *
    * @return The total number of potions in the inventory*/
    int getNumberOfPotions() const;
    //int const getCoins();
 
    /**
    * @brief Returns the total number of items in the inventory
    *
    * This function provides the total count of items currently stored in the inventory.
    *
    * @return The total number of items in the inventory*/
    int getNumberOfItems() const;

    /**
    * @brief Retrieves an item from the inventory by its index
    *
    * This function returns a pointer to the `Item` at the specified index. If the index is out of range or if
    * the item at that index is null, it throws an exception.
    *
    * @param itemIndex The index of the item to retrieve.
    * @return A pointer to the `Item` at the specified index.
    * @throws std::out_of_range If the index is out of the valid range.
    * @throws std::runtime_error If the item at the given index does not exist.*/
    Item* getItem(int itemIndex) const;

    /**
    * @brief Returns a list of all items in the inventory
    *
    * This function provides a vector containing all items currently in the inventory.
    *
    * @return A vector of pointers to all items in the inventory.*/
    std::vector<Item*> getItemList() const;
};

#endif // INVENTORY_H
