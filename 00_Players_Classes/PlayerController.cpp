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

Position PlayerController::getOldPosition() const { return m_playerOldPosition; }

char PlayerController::getTileType_nextPosition() {
	int nextPos_x = m_playerNextPosition.st_x;
	int nextPos_y = m_playerNextPosition.st_y;
	char tileType;

	tileType = m_actualRoom->m_tileField.at(nextPos_x).at(nextPos_y)->getTileType();
	return tileType;
}

void PlayerController::createNextPosition() {
	m_playerNextPosition = getOldPosition();
    switch (m_direction) {
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

void PlayerController::updateControlsPosition() {
    m_playerOldPosition = m_playerNextPosition;
}

void PlayerController::removeOldPlayerPosition_onTF() {
	m_actualRoom->m_tileField.at(m_playerOldPosition.st_x).at(m_playerOldPosition.st_y)->setTileType('.');
}

void PlayerController::setNextPlayerPosition_onTF() {
	m_actualRoom->m_tileField.at(m_playerNextPosition.st_x).at(m_playerNextPosition.st_y)->setTileType('P');
}

void PlayerController::setPlayerOnMap() {
	m_actualRoom->m_tileField.at(m_playerOldPosition.st_x).at(m_playerOldPosition.st_y)->setTileType('P');
}

void PlayerController::move(char tileType) {
    switch (tileType) {
	case '.':
	case 'I':
        removeOldPlayerPosition_onTF();
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
	case 'I':
		break;
	}
}

void PlayerController::travel(char tileType, bool& changeRoomYesOrNo) {
    removeOldPlayerPosition_onTF();
	changeRoomYesOrNo = true;
}

void PlayerController::processNextPosition(bool &changeRoomYesOrNo) {
	char tileType = getTileType_nextPosition();
	move(tileType);
	interact(tileType);
	if (tileType=='H' || tileType== 'O') travel(tileType, changeRoomYesOrNo);
}
