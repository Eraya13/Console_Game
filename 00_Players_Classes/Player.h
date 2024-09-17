#pragma once
#include "Inventory.h"
#include "Enemy.h"
#include "../05_FrontEndClasses/View.h"
#include "../02_Entity/Entity.h"

/**
 * @class Player
 * @brief Represents the player's character in the game.
 *
 * The `Player` class model represents the character that player controls in the game, inheriting from the `Entity` class.
 * It extends the base functionality of an entity by introducing the player's inventory, equipped armor, and weapon.
 * The class provides methods to interact with the player's inventory (adding, discarding, equipping items),
 * and engage in combat with enemies.
 *
 * The `Player` is a central game entity that keeps track of attributes such as attack, defense, health, and
 * experience points (XP). The player can also equip and use various items such as weapons and armor to influence
 * these attributes.
 *
 * @details
 * - The player's inventory allows for the collection and management of items like potions, armor, and weapons.
 * - Equipped items directly affect the player's attack and defense stats.
 * - Health management includes healing via potions.
 * - The player gains experience points (XP) from defeating enemies, which can potentially be used for leveling up.
 */
class Player : public Entity {
private:
    /**
    * @brief A pointer to the player's inventory.
    *
    * Holds the items the player has collected, such as potions, weapons, armor and coins. */
    Inventory* m_inventory;
    
    /**
    * @brief A pointer to the armor currently equipped by the player.
    *
    * Armor increases the player's defense and provides protection during combat.*/
    Armor* m_armor;

    /**
    * @brief A pointer to the weapon currently equipped by the player.
    *
    * Weapons are used to increase the player's attack power during combat.*/
    Weapon* m_weapon;
public:
    /**
    * @brief Constructs a Player object with a given name, health, and attack power.
    *
    * Initializes the player with specified attributes including name, health, and attack value.
    * An `Inventory` object is automatically created when the player is constructed.
    * Defense is initialized to a default value, and the armor and weapon are set to nullptr.
    *
    * @param name The name of the player character
    * @param health - The player's starting health points
    * @param attack - The player's initial attack power */
    Player(std::string name, int attack, int defense, int health, int xp);       // todo defense, level, xp

    /**
    * @brief Makes the player drink the specified potion to restore health.
    *
    * Directly uses the provided potion and its index in the inventory to restore health,
    * then removes the potion from the inventory.
    *
    * This method is called when player choose specific item that is potion and decides to use it.
    *
    * @param potion - A pointer to the potion to be consumed.
    * @param itemIndex - The index of the potion in the inventory. */
    void drinkPotion(Potion* potion, int itemIndex);
    
    /**
    * @brief Makes the player drink a potion to restore health.
    *
    * Searches the player's inventory for a potion, restores health based on the potion's
    * health bonus, and then discards the potion from the inventory.
    *
    * This method is called when player choose to drink potion from Inventory menu. */
    void drinkPotion();

    /**
    * @brief Restores the player's health by a specified amount get from potion.
    *
    *  This method increases the player's health by the given amount, up to a maximum limit.
    *
    * @param amount The number of health points to restore.*/
    void restoreHealth(int amount);

    /**
    * @brief Returns a list of items currently in the player's inventory.
    *
    * @return A vector of pointers to the items in the player's inventory.*/
    std::vector<Item*> getInventoryItemList();

    /**
    * @brief This method of player calls `Inventory` method to add an item to the player's inventory.
    *
    * @param item - A pointer to the item to be added.*/
    void addItemToInventory(Item* item);

    /**
    * @brief Discards an item from the player's inventory.
    *
    * This method removes and deletes the specified item from the player's inventory by calling the
    * corresponding method in the `Inventory` class.
    *
    * @param item - A pointer to the item to be discarded.
    * @param itemIndex - The index of the item in the inventory list. */
    void discardItem(Item* item, int itemIndex);

    /**
    * @brief Retrieves the total number of potions in the player's inventory.
    *
    * @return The number of potions the player currently has in their inventory.*/
    int getNumberOfPotions() const;

    /**
    * @brief Calculates the player's total attack power.
    *
    * This method retrieves the player's base attack value using `getAttack()`
    * and adds any bonus attack power provided by the currently equipped weapon.
    * If no weapon is equipped, only the base attack value is returned.
    * @brief Returns the total number of items in the player's inventory.

    * @return The player's total attack power, including weapon bonuses if applicable.
    */
    int getTotalAttackPower() const;

    /**
    **
    * @return The total count of items in the player's inventory.*/
    int getTotalNumberOfItems() const;

    /**
    * @brief Selects an item from the player's inventory based on the index.
    *
    * This method returns the item located at the specified index in the player's inventory.
    *
    * @param itemIndex The index of the item to select.
    * @return A pointer to the selected `Item` object.*/
    Item* selectItem(int itemIndex);

    /**
    * @brief Toggles weapon equipment.
    *
    * This method perform equipping or unqeuiping action whether the weapon is equipped or not
    * If the weapon is already equipped, it will be unequipped.
    * If the weapon is not equipped, it will be equipped.
    *
    * @param weapon A pointer to the Weapon object to be toggled. */
    void toggleEquipment(Weapon* weapon);

    /**
    * @brief Toggles weapon equipment.
    *
    * This method perform equipping or unqeuiping action whether the armor is equipped or not
    * If the armor is already equipped, it will be unequipped.
    * If the armor is not equipped, it will be equipped.
    *
    * @param armor A pointer to the Armor object to be toggled. */
    void toggleEquipment(Armor* armor);

    /**
    * @brief Equips a weapon to the player.
    *
    * If no weapon is currently equipped, the specified weapon is equipped.
    * If weapon is already equipped, it is unequipped and replaced by the new one.
    *
    * @param weapon A pointer to the Weapon object to be equipped. */
    void equip(Weapon* weapon);

    /**
    * @brief Equips armor to the player.
    *
    * If no armor is currently equipped, the specified armor is equipped.
    * If armor is already equipped, it is unequipped and replaced by the new one.
    *
    * @param armor A pointer to the Armor object to be equipped. */
    void equip(Armor* armor);
    /**
    * @brief Unequips the currently equipped weapon.
    *
    * This function sets the current weapon to unequipped state and removes it from the player. */
    void unequipWeapon();

    /**
    * @brief Unequips the currently equipped armor.
    *
    * This function sets the current armor to unequipped state and removes it from the player.*/
    void unequipArmor();

    /**
    * @brief Initiates a battle between the player and the specified enemy.
    *
    * @param Enemy A pointer to the `Enemy` object the player will battle. */
	void battle(Enemy* Enemy);

    void printInfo() override; // not used method yet
};

