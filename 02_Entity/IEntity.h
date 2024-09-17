#pragma once
#include <iostream>

/**
 * @class IEntity
 * @brief Interface for all entities in the game.
 *
 * The `IEntity` interface defines the basic contract for all entities that can exist in the game. It serves as a 
 * common interface for any object that can be placed on a tile within a room. Each tile can contain an entity 
 * represented by a pointer to an `IEntity` object, allowing for a flexible and extensible system for handling 
 * various types of entities in the game.
 *
 * @note The `IEntity` interface cannot be instantiated directly as it contains pure virtual functions. */
class IEntity {
public:
    /**
    * @brief Gets the name of the entity.
    *
    * This pure virtual method should be overridden to return the name of the entity.
    *
    * @return The name of the entity as a `std::string`. */
    virtual std::string getName() const = 0;

    /**
    * @brief Prints the information of the entity.
    *
    * This pure virtual method should be overridden to output details about the entity. */
    virtual void printInfo() = 0;
};
