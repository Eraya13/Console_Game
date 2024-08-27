#ifndef VIEW_H
#define VIEW_H
#include "../00_Players_Classes/Player.h"

class View
{
private:
    static Player* m_player;
public:
    // Statická metoda pro inicializaci ukazatele na hráče
    static void init(Player* player);
    static void inGameMenu_m();         // _m - sign for menu print
    static void playerStats();
    static void inventoryInfo_m();
    static void listInventoryItems();


    //void inventory_m();
    // FUTURE MENU
    // void NewGame_m();
    View();
};

#endif // VIEW_H
