#pragma once
#include "../02_Entity/Enemy.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Armor.h"
#include "Inventory.h"

/**
 * @class EntityManager.
 * @brief Represents the player character in the game.
 *
 * The Player class manages the player's attributes such as health, attack, defense, inventory, and equipped items (armor and weapon).
 * It provides methods to interact with the player's inventory, manage health, and engage in combat with enemies. */
class Player {
private:
/**
 * @brief The name of the player character.
 */
    std::string m_name;

    /**
    * @brief The player's current health points.
    *
    * Determines if the player is hurt or not. If there is no damage the value is 100 HP and if health reaches 0,
    * the player is defeated and game is over. */
    int m_health;

    /**
    * @brief The player's attack power.
    *
    * Used to calculate the damage dealt to enemies during combat without weapon, weapon adds bonus to attack. */
    int m_attack;

    /**
    * @brief The player's defense value.
    *
    * Reduces incoming damage from enemies based on this value. The value stores only natural defense without any armor.*/
    int m_defense;

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
    Player(std::string name, int health, int attack);       // todo defense, level, xp

    /**
    * @brief Retrieves the player's current health points.
    *
    * @return The current health value of the player.
    */
    int getHealth() const;
    /**
    * @brief Retrieves the player's attack power.
    *
    * @return The player's attack value.
    */
    int getAttack() const;

    /**
    * @brief Retrieves the player's name
    *
    * @return The name of the player as a string.
    */
    std::string getName() const;

	void setHealth(int minusHealth);

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

    int getTotalAttackPower() const;
    /**
    * @brief Returns the total number of items in the player's inventory.
    *
    * @return The total count of items in the player's inventory.*/
    int getTotalNumberOfItems();

    /**
    * @brief Selects an item from the player's inventory based on the index.
    *
    * This method returns the item located at the specified index in the player's inventory.
    *
    * @param itemIndex The index of the item to select.
    * @return A pointer to the selected `Item` object.*/
    Item* selectItem(int itemIndex);

    void toggleEquipment(Weapon* weapon);
    void toggleEquipment(Armor* armor);

    void equip(Weapon* weapon);

    void equip(Armor* armor);

    void unequipWeapon();
    void unequipArmor();
    /**
    * @brief Initiates a battle between the player and the specified enemy.
    *
    * @param Enemy A pointer to the `Enemy` object the player will battle. */
	void battle(Enemy* Enemy);
};

