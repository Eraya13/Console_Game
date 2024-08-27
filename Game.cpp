#include "Game.h"


Game::Game() {
	m_player = nullptr;
	m_map = nullptr;
	m_actualRoom = nullptr;
	m_playerControls = nullptr;
	m_gameOngoing = true;
}

void Game::createMap(std::string filename) {
	m_map = new Map(filename);
}

void Game::setCursor() {
    ConsoleManager::setCursorForRoomPrint();
    ConsoleManager::setCursorINvisible();
}

void Game::setGameElements() {
    SetConsoleOutputCP(65001);	// nastavi kodovani na UTF-8
    // create GameElements
	system ("cls");
    m_player = new Player("Derien", 100, 40);   // poupravit
	createMap("LocationsNames.txt");
	// real set GameElements
	m_actualRoom = m_map->getRoom(START_LOCATION, START_ROOM);					// call room funkce - nutno drzet aktualni!
	m_playerControls = new Controls (6, 7, m_player, m_actualRoom);
	m_playerControls->setPlayerOnMap();
    // debug prints:
    system ("cls");
    std::cout << "\nGame elements are set succesfully\n";
	system("pause");
	system ("cls");
    setCursor();
}

void Game::testFunction() {

}

// Hlavni funkce hry:
void Game::gameLoop() {
	// printActualRoom -> Village
    ConsoleManager::printRoom(m_actualRoom);
	while (m_player->getHealth() > 0 && m_gameOngoing) {
        performAction(decideActionType());
        setCursor();
        if (!m_gameOngoing) continue;       // přeruší se while cyklus a ukončí se hra...
        ConsoleManager::printRoom(m_actualRoom);		// ma se printnout znovu, pokud se skutecne neco stane...
    }
}

// rozhodne co za akce se má provést - pohyb / zobrazení menu / ukončení hry
ActionType Game::decideActionType() {
	bool inputOk = true;
	char key;
	do {
        key = ConsoleManager::readInput_onMap();
		switch (key) {
			case 'W':
			case 'A':
			case 'S':
			case 'D':
				m_playerControls->setDirection(key);
				return ActionType::Movement;
			case '\t':				// TAB
				return ActionType::InGameMenu;	
		}
    } while (key != 27);			// ESC - nefunguje
	return ActionType::QuitGame;
}

// provede akci - na základě hodnoty, která se vrátí z decideActionType()
void Game::performAction(ActionType action) {
	bool changeRoomYesOrNo = false;		// vychozi hodnota
	switch (action) {
		case ActionType::Movement:
			// vytvoreni nove pozice na zaklade drivejsiho key
			m_playerControls->createNextPosition();
			// posoudi se, zda se hrac pohne nebo bude mit interakci
			m_playerControls->analyzeAperformNextPosition(changeRoomYesOrNo);
			if (changeRoomYesOrNo == true) { 
				// todo actions for settting Travel Menu
				std::cout << "\n\t***Hrac bude presun na jinou mapu***\n";
                ConsoleManager::setTextVisible();
                system("pause");
                system ("cls");
			}
			break;
		case ActionType::InGameMenu:	 // Setting for Menu Print - InGameMenuSetting();
            ConsoleManager::setTextVisible();        // text je již vidět (zobrazování mapy ho skrylo)
            ConsoleManager::setCursorVisible();      // curzor je viditelný
            ConsoleManager::displayInGameMenu();     // zobrazí se InGameMenu
            ConsoleManager::cursorNavigation(22, 4);  // 22 4 Hráči je umožněna navigace mezi options InGameMenu
            ConsoleManager::executeInGameMenuOption(m_gameOngoing);  // Hráč zmáčkl "Enter" a posuzuje se, zda náhodou nevybral Exit Game (Konec hry)
            break;
        case ActionType::QuitGame:
            m_gameOngoing = false;
            break;
	}
}





