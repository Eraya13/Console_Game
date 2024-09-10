#include "Player.h"


Player::Player(std::string name, int health, int attack) {
	m_name = name;
	m_health = health;
	m_attack = attack;
    m_armor = nullptr;
    m_weapon = nullptr;
    m_inventory = new Inventory();
}

int Player::getHealth() {
	return m_health;
}

int Player::getAttack() {
	return m_attack;
}

std::string Player::getName() {
    return m_name;
}

void Player::setHealth(int minusHealth) {
	m_health -= minusHealth;
}

void Player::restoreHealth(int amount) {
    int maxHealth = 100;
    if (m_health + amount <= maxHealth) {
        m_health += amount;
        // todo View!!
        std::cout << "\tHealth restored by " << amount << " HP.\n"
                  << "\tPlayer's health is now " << getHealth() << " HP.\n\n";
        system("pause");
        system("cls");
        // todo View:: showPlayersHealth - show Player's health
    }
    else {

    }
}

void Player::battle(Enemy* Enemy) {
	std::cout << "You defeated your enemy.\n";
}

//**** Inventory methods

std::vector<Item*> Player::getInventoryItemList() {
    return m_inventory->getItemList();
}

int Player::getNumberOfPotions() {
    return m_inventory->getNumberOfPotions();
}

int Player::getTotalNumberOfItems() {
    return m_inventory->getNumberOfItems();
}

Item* Player::selectItem(int itemIndex) {
    return m_inventory->getItem(itemIndex);
}

void Player::discardItem(Item* item, int itemIndex) {
    m_inventory->discardItem(item, itemIndex);
}

void Player::drinkPotion() {
    Item* potion = nullptr;
    int index = -1;

    m_inventory->findPotion(potion, index);

    if (potion != nullptr) {
        int healthBonus = static_cast<Potion*>(potion)->getHealthBonus();
        restoreHealth(healthBonus);
        m_inventory->discardItem(potion, index);
    } else {
        // todo View!!!
        std::cout << "No potion found in inventory.\n";
        system("pause");
    }
}

void Player::drinkPotion(Potion* potion, int itemIndex) {
    int healthBonus = potion->getHealthBonus();
    restoreHealth(healthBonus);
    m_inventory->discardItem(potion, itemIndex);
}

