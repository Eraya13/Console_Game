#pragma once
#include "IEntity.h"


/**
 * @class Entity
 * @brief Represents a general entity of living beings in the game.
 *
 * The `Entity` class is a concrete implementation of `IEntity` and provides additional attributes and methods
 * specific to entities that have attack, defense, health, and experience points. It serves as a base class
 * for more specific entity types like `Player` and `Enemy`. */
class Entity : public IEntity {
protected:
    std::string m_name; ///< name of the entity.
    int m_attack;  ///< attack value of the entity.
    int m_defense; ///< defense value of the entity.
    int m_health; ///< health value of the entity.
    int m_xp; ///< experience points of the entity.
public:
    /**
    * @brief Constructs a new `Entity` object.
    *
    * Initializes an entity with a given name, attack, defense, health, and experience points.
    *
    * @param name The name of the entity.
    * @param attack The attack value of the entity.
    * @param defense The defense value of the entity.
    * @param health The health value of the entity.
    * @param xp The experience points of the entity. */
    Entity(std::string name, int attack, int defense, int health, int xp);

    /**
    * @brief Constructs a new `Entity` object.
    *
    * This constructor is created for creating entity with full health.
    * The entitiy is inicitialized with a given name, attack, defense, full health and experience points.
    *
    * @param name The name of the entity.
    * @param attack The attack value of the entity.
    * @param defense The defense value of the entity.
    * @param xp The experience points of the entity. */
    Entity(std::string name, int attack, int defense, int xp);

    /**
    * @brief Gets the name of the entity.
    *
    * @return The name of the entity */
    std::string getName() const;

    /**
    * @brief Gets the attack value of the entity.
    *
    * @return The attack value of entity. */
    int getAttack() const;

    /**
    * @brief Gets the defense value of the entity.
    *
    * @return The defense value of entity. */
    int getDefence() const;

    /**
    * @brief Gets the health value of the entity.
    *
    * @return The health value of entity. */
    int getHealth() const;

    /**
    * @brief Gets the experience points of the entity.
    *
    * @return The experience points of the Entity*/
    int getXP() const;
    
    /**
    * @brief Sets the name of the entity.
    *
    * @param name The new name for the entity. */
    void setName(std::string name);
     
    /**
    * @brief Sets the attack value of the entity.
    *
    * @param attack The new attack value for the entity. */
    void setAttack(int attack);


    /**
    * @brief Sets the defense value of the entity.
    *
    * @param defense The new defense value for the entity. */
    void setDefense(int defense);

    /**
    * @brief Sets the health value of the entity.
    *
    * @param health The new health value for the entity. This can also be used to heal the entity. */
    void setHealth(int health);
    
    /**
    * @brief Calculates damage based on the entity's attack value.
    *
    * This method is intended for battle scenarios but is currently commented out.
    *
    * @param attack The attack value to be used in the damage calculation. */
    // void calculateDamage(int attack);

    virtual void printInfo() = 0;

    /**
    * @brief Updates the entity's health based on damage received.
    *
    * This method is intended for battle scenarios but is currently commented out.
    *
    * @param damage The amount of damage to apply to the entity's health. */
    // for battle - updateHealth(int damage)              // bude fungovat + i minus;
};
