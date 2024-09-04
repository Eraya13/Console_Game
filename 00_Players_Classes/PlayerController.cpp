#include "PlayerController.h"

PlayerController::PlayerController(int x, int y, Player* player, Room* room) {
	m_player = player;
	m_actualRoom = room;
	m_playerOldPosition = { x, y };
	m_playerNextPosition = { 99, 99 };
	m_direction = 'N';
}

void PlayerController::setDirection(char key) {
	m_direction = key;
}

// gettery:
Position PlayerController::getOldPosition() const { return m_playerOldPosition; }

char PlayerController::getTileType_nextPosition() {
	int nextPos_x = m_playerNextPosition.st_x;
	int nextPos_y = m_playerNextPosition.st_y;
	char tileType;

	tileType = m_actualRoom->m_tileField.at(nextPos_x).at(nextPos_y)->getTileType();
	return tileType;
}

// pozice sprava
void PlayerController::createNextPosition() {
	m_playerNextPosition = getOldPosition();
	switch (m_direction) {				// uprava nextPozice dle directionu
	case 'W':
		m_playerNextPosition.st_x--;
		break;
	case 'S':
		m_playerNextPosition.st_x++;
		break;
	case 'A':
		m_playerNextPosition.st_y--;
		break;
	case 'D':
		m_playerNextPosition.st_y++;
		break;
	}
}
// settery pozice
void PlayerController::updateControlsPosition() {
	m_playerOldPosition = m_playerNextPosition;		// nextPozice se prepisuje - neni treba menit
}

void PlayerController::setOldPlayerPosition_onTF() {
	// nastaveni na noneTile - "smazani" reprezentovane pozice
	m_actualRoom->m_tileField.at(m_playerOldPosition.st_x).at(m_playerOldPosition.st_y)->setTileType('.');
}

void PlayerController::setNextPlayerPosition_onTF() {
	// nastaveni na reprezentovanou pozici hrace
	m_actualRoom->m_tileField.at(m_playerNextPosition.st_x).at(m_playerNextPosition.st_y)->setTileType('P');
}

void PlayerController::setPlayerOnMap() {
	m_actualRoom->m_tileField.at(m_playerOldPosition.st_x).at(m_playerOldPosition.st_y)->setTileType('P');
}

void PlayerController::move(char tileType) {
	switch (tileType) {			// posouzeni pozice - if good ulozi se na starou
	case '.':
	case 'I':
		setOldPlayerPosition_onTF();
		setNextPlayerPosition_onTF();
		updateControlsPosition();
		break;
	}
}

void PlayerController::interact(char tileType) {
	switch (tileType) {
	case 'E':
		// battleOnTily()
		break;
	case 'N':
		// 
		break;
	case 'I':
		break;
	}
}

void PlayerController::travel(char tileType, bool& changeRoomYesOrNo) {
	setOldPlayerPosition_onTF();
	changeRoomYesOrNo = true;
}

// analyzujeNextPozici a podle ni nastavie hodnoty pro movement ci interakci
void PlayerController::analyzeAperformNextPosition(bool &changeRoomYesOrNo) {
	char tileType = getTileType_nextPosition();
	move(tileType);
	interact(tileType);
	if (tileType=='H' || tileType== 'O') travel(tileType, changeRoomYesOrNo);
}
