#pragma once
#include "IEntity.h"
/**
 * @class Item
 * @brief Represents an item in the game.
 *
 * The `Item` class is an abstract class derived from `IEntity` that provides common attributes and methods
 * for various types of items in the game, such as weapons, armor, and potions. It includes functionality
 * for managing item details and category information.
 *
 * @note The `Item` class cannot be instantiated directly as it contains pure virtual functions. */
class Item: public IEntity {
protected:
    std::string m_name;         ///< The name of the item.
    std::string m_description;  ///< Detailed description of the item.
    std::string m_info;         ///< Additional information about the item.
    std::string m_category;     ///< Category of the item, such as "armor", "healing_potion", or "weapon".
public:
    /**
    * @brief Constructs a new `Item` object.
    *
    * Initializes an item with the specified name.
    *
    * @param name The name of the item. */
    Item(std::string name);
    /**
    * @brief Gets the name of the item.
    *
    * @return The name of the item. */
    std::string getName() const;
    /**
    * @brief Gets the category of the item.
    *
    * @return The category of the item. */
    std::string getCategory() const;

    /**
    * @brief Gets additional information about the item.
    *
    * @return The additional information about the item */
    std::string getInfo() const;

    /**
    * @brief Sets the category of the item.
    *
    * This pure virtual method should be overridden to allow setting the item's category.
    *
    * @param category The category to set. */
    virtual void setCategory(std::string category) = 0;

    /**
    * @brief Prints information about the item.
    *
    * This pure virtual method should be overridden to output item's information. */
    virtual void printInfo() = 0;

    ~Item();
};
