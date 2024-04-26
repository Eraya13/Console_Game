#pragma once
#include <iostream>
#include <vector>

#include "../02_Entity/Enemy.h"
#include "../02_Entity/NPC.h"


// short note: vektory / arraye není nutné naplňovat a inicializovat sami jsou třídou objektů

// Note: Roomka by neměla mít přístup k tomu, aby přidávala Entity do listu...
	// EntityManager si pořeší z čeho bude vyčítat jednotlivé Entity
	// EntityManager akorát musí obdržet od Roomky konkrétní instrukce:
	//	-- jaké fily jsou určeny pro tvorbu Entit dané Roomky
	// EntityManager spravuje vznik, zánik a drží si informace o Entitách pro danou roomku

class EntityManager {
private:
    std::vector<Enemy*> l_enemies;
    std::vector<NPC*> l_NPCs;
public:
    EntityManager();
    void addEntity(Enemy* enemy);
    void addEntity(NPC* NPC);
    
    void fillListEnemies();             // future: automatizovaná funkce, která na základě souboru bude přidávat enemy do listu, dokud není end of file
    // metoda, která vráti referenci Tile na určitou Entitu - podle indexu v poli
        // - za pomocí této metody, chci procházet index po indexu vektor entit, pokud narazim na příslušnou entitu, která by měla mít danou referenci 
    Enemy* getEnemyReference(int index) const;           // příjemce je tila z Roomky m_tileField;
    NPC* getNPCReference(int index) const;
    
    /*void destroyEntity(Enemy* enemy);
    void destroyEntity(NPC* NPC);*/
};