#pragma once
#include <vector>

#include "../02_Entity/Enemy.h"


// short note: vektory / arraye není nutné naplňovat a inicializovat sami jsou třídou objektů

// Note: Roomka by neměla mít přístup k tomu, aby přidávala Entity do listu...
	// EntityManager si pořeší z čeho bude vyčítat jednotlivé Entity
	// EntityManager akorát musí obdržet od Roomky konkrétní instrukce:
	//	-- jaké fily jsou určeny pro tvorbu Entit dané Roomky
	// EntityManager spravuje vznik, zánik a drží si informace o Entitách pro danou roomku
/**
 * @class EntityManager.
 * @brief Manages the creating of Entities in the game.
 *
 * This class is responsible for storing and managing entities such as items and enemies. It initializes a predefined list based on text filed that specifies the stats of entity.
 * of enemies and provides methods to access them.*/
class EntityManager {
private:

    std::vector<Enemy*> l_enemies; ///< List of enemy pointers.
    // std::vector<Item*> m_items; ///< List of item pointers
public:
    /**
    * @brief Constructs an EntityManager and populates the list of enemies.
    *
    * The constructor initializes the EntityManager by calling fillListEnemies() to populate
    * the internal list with predefined enemies. */
    EntityManager();

    /**
    * @brief Adds a new enemy to the list.
    * @param enemy Pointer to the Enemy object to be added. */
    void addEntity(Enemy* enemy);
     
    /**
    * @brief Fills the list with predefined enemies based on text file.
    * This method will be implemented now it is still in development.
    * This method initializes the list with a set of predefined enemies. */
    void fillListEnemies();
    
    /**
    * @brief Retrieves a reference to an enemy based on its index in the list.
    * @param index The index of the enemy in the list.
    * @return Pointer to the Enemy object at the specified index.
    * @throws std::out_of_range if the index is out of the bounds of the list. */
    Enemy* getEnemyReference(int index) const;           // příjemce je tila z Roomky m_tileField;
    
    //void destroyEntity(Enemy* enemy);
};
