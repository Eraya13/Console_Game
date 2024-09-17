#include "Player.h"


Player::Player(std::string name, int attack, int defense, int health, int xp) : Entity(name, attack, defense, health, xp) {
    m_armor = nullptr;
    m_weapon = nullptr;
    m_inventory = new Inventory();
}

void Player::printInfo() {
    std::cout  << "I am " << m_name;
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
    else { }
}

void Player::battle(Enemy* Enemy) {
	std::cout << "You defeated your enemy.\n";
}

//**** Inventory methods

std::vector<Item*> Player::getInventoryItemList() {
    return m_inventory->getItemList();
}

int Player::getNumberOfPotions() const {
    return m_inventory->getNumberOfPotions();
}

int Player::getTotalNumberOfItems() const {
    return m_inventory->getNumberOfItems();
}

Item* Player::selectItem(int itemIndex) const {
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
        View::noPotionLeft();
        system("pause");
    }
}

void Player::drinkPotion(Potion* potion, int itemIndex) {
    int healthBonus = potion->getHealthBonus();
    restoreHealth(healthBonus);
    m_inventory->discardItem(potion, itemIndex);
}

int Player::getTotalAttackPower() const {
    return m_weapon->getAttackBonus() + getAttack();
}

void Player::equip(Weapon* weapon) {
    if (m_weapon == nullptr) {
        m_weapon = weapon;
        m_weapon->setEquipped();
    }
    else {
        m_weapon->setUnequipped();
        m_weapon = weapon;
        m_weapon->setEquipped();
    }
}


void Player::equip(Armor* armor) {
    if (m_armor == nullptr) {
        m_armor = armor;
        m_armor->setEquipped();
    }
    else {
        m_armor->setUnequipped();
        m_armor = armor;
        m_armor->setEquipped();
    }
}

void Player::unequipWeapon() {
    m_weapon->setUnequipped();
    m_weapon = nullptr;
}

void Player::unequipArmor() {
    m_armor->setUnequipped();
    m_armor = nullptr;
}

void Player::toggleEquipment(Weapon* weapon) {
    if (m_weapon != weapon) {
        equip(weapon);
    }
    else {
        unequipWeapon();
    }
}

void Player::toggleEquipment(Armor* armor) {
    if (m_armor != armor) {
        equip(armor);
    }
    else {
        unequipArmor();
    }
}
