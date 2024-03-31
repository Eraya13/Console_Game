#pragma once
#include <iostream>
#include "ErrorLog.h"
#include "Players_Classes/Player.h"
#include "Players_Classes/Controls.h"
#include "GlobalVariables.h"
#include "03_Map/Map.h"
#include "FrontEndClasses/GUI.h"
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
	bool m_gameState;
	// private funkce:
	void createMap(std::string filename);
	ActionType decideActionType();
	void performAction(ActionType action);

public:
	Game();
	// create Player + his classes & map vector etc
	void setGameElements();
	void gameLoop();
	void testFunction();
};
