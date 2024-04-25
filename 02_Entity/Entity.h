#pragma once
#include <iostream>
#include "../02_Entity/IEntity.h"

class Entity : public IEntity {
protected:
    std::string m_name;
    int m_attack;
    int m_defense;
    int m_health;
    int m_xp;
    // Inventory* m_inventory;
public:
    Entity(std::string name, int attack, int defense, int health, int xp);
    int getAttack() const;
    int getDefence() const;
    int getHealth() const;
    int getXP() const;
    std::string getName() const;
    // for upgrades and basic settings
    void setName(std::string name);
    void setAttack(int attack);
    void setDefense(int defense);
    void setHealth(int health);     // also for heal health
    
            // battle functions for Player and Enemy
    // void calculateDamage(int attack);
    // for battle - updateHealth(int damage)              // bude fungovat + i minus;

};