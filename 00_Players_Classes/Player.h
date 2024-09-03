#pragma once
#include "../02_Entity/Enemy.h"
#include "../02_Entity/Weapon.h"
#include "../02_Entity/Armor.h"
#include "Inventory.h"

class Player {
private:
	std::string m_name;
	int m_health;
	int m_attack;
    int m_defense;
    Inventory* m_inventory;
    Armor* m_armor;
    Weapon* m_weapon;
public:
    Player(std::string name, int health, int attack);       // todo defense, level, xp
    // **Player personal methods**
    // gettery
	int getHealth();
	int getAttack();
    std::string getName();
	// settery
	void setHealth(int minusHealth);

    // Inventory methods
    std::vector<Item*> getInventoryItemList();
    void addItemToInventory(Item* item);
    // akce pro spotrebovani potionu vcetne jeho odstraneni, vymazani z inventare a vyhealovani hrace
    void drinkPotion();
    void discardItem(Item* item, int itemIndex);
    int getNumberOfPotions();
    int getTotalNumberOfItems();
    Item* selectItem(int itemIndex);
    // Armor methods

    // Weapon methods


    // entity funkce:
	void battle(Enemy* Enemy);
};

