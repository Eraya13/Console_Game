#include "Game.h"


Game::Game() {
	m_player = nullptr;
	m_map = nullptr;
	m_actualRoom = nullptr;
	m_playerControls = nullptr;
	m_gui = nullptr;
	m_gameOngoing = true;
}

void Game::createMap(std::string filename) {
	m_map = new Map(filename);
}

void Game::setCursor() {
	m_gui->setDefaultCursorOnRoom();
	m_gui->setCursorINvisible();
}

void Game::setGameElements() {
	// create GameElements
	system ("cls");
	m_player = new Player("Derien", 100, 40);
	createMap("LocationsNames.txt");
	// real set GameElements
	m_actualRoom = m_map->getRoom(START_LOCATION, START_ROOM);					// call room funkce - nutno drzet aktualni!
	m_playerControls = new Controls (6, 7, m_player, m_actualRoom);
	m_playerControls->setPlayerOnMap();
	m_gui = new GUI();
	SetConsoleOutputCP(65001);	// nastavi kodovani na UTF-8
    //setCursor();
    system ("cls");
    std::cout << "\nGame elements are set succesfully\n";
	system("pause");
	system ("cls");
}

void Game::testFunction() {

}

// Hlavni funkce hry:
void Game::gameLoop() {
	m_gui->setCursorINvisible();
	// printActualRoom -> Village
	m_gui->printRoom(m_actualRoom);
	while (m_player->getHealth() > 0 && m_gameOngoing) {
		performAction(decideActionType());
		if (!m_gameOngoing) continue;
		setCursor();
		m_gui->printRoom(m_actualRoom);			// ma se printnout znovu, pokud se skutecne neco stane...
	}
}

// rozhodne co za akce se má provést - pohyb / zobrazení menu / ukončení hry
ActionType Game::decideActionType() {
	bool inputOk = true;
	char key;
	do {
		key = m_gui->readInput_onMap();
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
                m_gui->setTextVisible();
				std::cout << "\n\t***Hrac bude presun na jinou mapu***\n";
			}
			break;
		case ActionType::InGameMenu:	 // Setting for Menu Print - InGameMenuSetting();
            m_gui->setTextVisible();        // text je již vidět (zobrazování mapy ho skrylo)
            m_gui->setCursorVisible();      // curzor je viditelný
            m_gui->displayInGameMenu();     // zobrazí se InGameMenu
            m_gui->cursorNavigation(22,5);  // Hráči je umožněna navigace mezi options InGameMenu
            m_gui->displayMenuOptions(m_gameOngoing);  // Hráč zmáčkl "Enter" a posuzuje se, zda náhodou nevybral Exit Game (Konec hry)
            m_gui->setCursorINvisible();  // Kurzor je neviditelný
            break;
        case ActionType::QuitGame:
            m_gameOngoing = false;
            break;
	}
}





