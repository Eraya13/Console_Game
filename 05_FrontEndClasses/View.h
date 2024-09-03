#ifndef VIEW_H
#define VIEW_H
#include <vector>

#include "../00_Players_Classes/Player.h"
#include "../00_Players_Classes/Inventory.h"



class View
{
private:
public:
    static Player* m_player;
    static Inventory* m_inventory;
    // Statická metoda pro inicializaci ukazatele na hráče
    static void init(Player* player);
    static void initInventory(Inventory* inventory);
    static void inGameMenu_m();         // _m - sign for menu print
    static void listInventoryItems();
    static void Inventory_m();
    static void playerStats();

    // FUTURE MENU
    // void NewGame_m();
};

#endif // VIEW_H
