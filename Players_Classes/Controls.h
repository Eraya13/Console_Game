#pragma once
#include "PositionStruct.h"
#include "Player.h"
#include "../03_Map/Room.h"
#include "../03_Map/Tile.h"

class Controls {
private:
	char m_direction;		// smer pro NextPozici
	Position m_playerOldPosition;
	Position m_playerNextPosition;
	Room* m_actualRoom;
	Player* m_player;
	// settery:
	void updateControlsPosition();
	void setOldPlayerPosition_onTF();
	void setNextPlayerPosition_onTF();
	// others:
	void move(char tileType);
	void interact(char tileType);
	void travel(char tileType, bool& changeRoomYesOrNo);			// predavani adresy s hodnotou - nutnost, aby promenna byla znama pred zavolanim teto funkce!!

public:
	Controls(int x, int y, Player* player, Room* room);			// x = row	y = column

	// position func
	void createNextPosition();
	void analyzeAperformNextPosition(bool& changeRoomYesOrNo);

	// gettery:
	Position getOldPosition();
	//Position getNextPosition();			bude se hodit pro portaly

	char getTileType_nextPosition();

	// settery:
	//void setNewRoom(Room* newRoom);

	// settery pozice:
	void setPlayerOnMap();			// nastavi dle Oldpozice "P" reprezentaci
	void setDirection(char key);
};

