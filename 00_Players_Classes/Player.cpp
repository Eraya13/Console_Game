#include "Player.h"


Player::Player(std::string name, int health, int attack) {
	m_name = name;
	m_health = health;
	m_attack = attack;
    m_armor = nullptr;
    m_weapon = nullptr;
    m_inventory = new Inventory();
}

int Player::getHealth() const {
	return m_health;
}

int Player::getAttack() const {
	return m_attack;
}

std::string Player::getName() const {
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

int Player::getNumberOfPotions() const {
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

int Player::getTotalAttackPower() const {
    return m_weapon->getAttackBonus() + getAttack();
}

void Player::equip(Weapon* weapon) {
    system ("cls");
    if (m_weapon == nullptr) {
        m_weapon = weapon;
        m_weapon->setEquipped();
    }
    else {
        m_weapon->setUnequipped();
        m_weapon = weapon;
        m_weapon->setEquipped();
    }
    // zde volat View... OR jen provést akce a podle návratové hodnoty volat toto níže...
    int totalAttackPower = m_weapon->getAttackBonus() + getAttack();
    std::cout << "You have equipped the " << m_weapon->getName() << " (+ " << m_weapon->getAttackBonus() << " attack power).\n";
    std::cout << "Your total attack power is " << totalAttackPower << std::endl;
    system("pause");
}

void Player::equip(Armor* armor) {
    system ("cls");
    if (m_armor == nullptr) {
        m_armor = armor;
        m_armor->setEquipped();
    }
    else {
        m_armor->setUnequipped();
        m_armor = armor;
        m_armor->setEquipped();
    }
    // zde volat View... OR jen provést akce a podle návratové hodnoty volat toto níže...
    //int totalDefensePower = m_armor->getDefenseBonus() + getDefense();
    std::cout << "You have equipped the " << m_armor->getName() << " (+ " << m_armor->getDefenseBonus() << " defense power).\n";
    //std::cout << "Your total defense power is " << totalDefensePower << std::endl;
    system("pause");
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
