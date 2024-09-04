#include "EntityManager.h"

EntityManager::EntityManager() {
    fillListEnemies();
    // fillListNPC();
}

void EntityManager::addEntity(Enemy* enemy) {
    l_enemies.push_back(enemy);
}

void EntityManager::fillListEnemies() {
    addEntity(new Enemy("Dark Knight",40, 10, 100, 250));
    addEntity(new Enemy("Slime",20, 5, 50, 100));
    addEntity(new Enemy("Goblin",30, 10, 100, 200));
    addEntity(new Enemy("Orc",50, 15, 100, 300));
}


Enemy* EntityManager::getEnemyReference (int index) const {
    return l_enemies.at(index);
}
