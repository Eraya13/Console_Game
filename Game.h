#pragma once
#include "ErrorLog.h"
#include "00_Players_Classes/Player.h"
#include "00_Players_Classes/Controls.h"
#include "03_Map/Map.h"
#include "05_FrontEndClasses/GUI.h"
#include "01_Enums/ActionType.h"

//TODO ERRORLOG globalem nebo singletonem

class Game {
private:
	// constants:
	const int START_ROOM = 0;
	const int START_LOCATION = 0;
	// Entity
	Player* m_player;
	Map* m_map;
	Room* m_actualRoom;
	Controls* m_playerControls;
	GUI* m_gui;
	bool m_gameOngoing;
	// private funkce:
	void createMap(std::string filename);
	ActionType decideActionType();
	void performAction(ActionType action);
	void setCursor();

public:
	Game();
	// create Player + his classes & map vector etc
	void setGameElements();
	void gameLoop();
	void testFunction();
};

