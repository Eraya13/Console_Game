#include "Game.h"

Game::Game() {
	m_player = nullptr;
	m_map = nullptr;
	m_actualRoom = nullptr;
	m_playerControls = nullptr;
	m_gui = nullptr;
	m_gameState = true;
}

void Game::createMap(std::string filename) {
	m_map = new Map(filename);
}

void Game::setGameElements() {
	// create GameElements
	m_player = new Player("Derien", 100, 40);
	createMap("LocationsNames.txt");
	// real set GameElements
	m_actualRoom = m_map->getRoom(START_LOCATION, START_ROOM);					// call room funkce - nutno drzet aktualni!
	m_playerControls = new Controls (6, 7, m_player, m_actualRoom);
	m_playerControls->setPlayerOnMap();
	
	m_gui = new GUI();
	m_gui->setDefaultCursorOnRoom();
	m_gui->toggleCursorVisibility();
	std::cout << "\nGame elements are set succesfully\n";
	system("pause");
	system ("cls");
}

void Game::testFunction() {

}

// Hlavni funkce hry:
void Game::gameLoop() {
	// printActualRoom -> Village
	m_gui->printRoom(m_actualRoom);
	while (m_player->getHealth() > 0 && m_gameState == true ) {
		bool changeRoomYesOrNo = false;	
		performAction(decideActionType());
		m_gui->printRoom(m_actualRoom);			// ma se printnout znovu, pokud se skutecne neco stane...
	}
}

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
			case '\t':					// TAB
				return ActionType::InGameMenu;	
		}
	} while (key != 27);			// ESC
	return ActionType::QuitGame;
}

void Game::performAction(ActionType action) {
	if (action == ActionType::Movement) {
		bool changeRoomYesOrNo = false;
		// vytvoreni nove pozice na zaklade drivejsiho key
		m_playerControls->createNextPosition();
		// posoudi se, zda se hrac pohne nebo bude mit interakci
		m_playerControls->analyzeAperformNextPosition(changeRoomYesOrNo);
		if (changeRoomYesOrNo == true) {			//TODO
			std::cout << "\n\t***Hrac bude presun na jinou mapu***\n";
		}
	}
	else if (action == ActionType::QuitGame) {
		m_gameState = false;
	} 
	else {
		// displayInGameMenu()
	}
}





