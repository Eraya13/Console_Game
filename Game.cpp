#include "Game.h"

Game::Game() {
	m_player = nullptr;
	m_map = nullptr;
	m_actualRoom = nullptr;
    m_playerController = nullptr;
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
    SetConsoleOutputCP(65001);	// sets coding to UTF-8
    // Here are created game elements
	system ("cls");
    m_player = new Player("Derien", 40, 40);
	createMap(Map::LOCATION_NAMES);
	// setting game elements
    m_actualRoom = m_map->getRoom(START_LOCATION, START_ROOM);
    m_playerController = new PlayerController (6, 7, m_player, m_actualRoom);
    m_playerController->setPlayerOnMap();
    setCursor();
}

void Game::testFunction() {}

void Game::gameLoop() {
    ConsoleManager::printRoom(ConsoleManager::AdjustTileFieldToSquareAspect(m_actualRoom));
	while (m_player->getHealth() > 0 && m_gameOngoing) {
        performAction(decideActionType());
        setCursor();
        // if m_gameOngoing is false - the app will stop, otherwise the gameLoop continue
        if (!m_gameOngoing) continue;       
        ConsoleManager::printRoom(ConsoleManager::AdjustTileFieldToSquareAspect(m_actualRoom));
    }
}

ActionType Game::decideActionType() {
	bool inputOk = true;
	char key;
	do {
        key = ConsoleManager::readUserInput();
		switch (key) {
			case 'W':
			case 'A':
			case 'S':
			case 'D':
                m_playerController->setDirection(key);
				return ActionType::Movement;
			case '\t':				// TAB key
				return ActionType::InGameMenu;	
		}
    } while (key != 27);		// ENTER key
	return ActionType::QuitGame;
}

void Game::performAction(ActionType action) {
	bool changeRoomYesOrNo = false;		// default value - no travel is required right away
	switch (action) {
		case ActionType::Movement:
			// It creates a new position according to WASD
            m_playerController->createNextPosition();
			// analyze if movement is possible to the next position
            m_playerController->processNextPosition(changeRoomYesOrNo);
			if (changeRoomYesOrNo == true) { 
				// todo actions for settting Travel Menu
				std::cout << "\n\t***Hrac bude presun na jinou mapu***\n";
                ConsoleManager::setTextVisible();
                system("pause");
                system ("cls");
			}
			break;
		case ActionType::InGameMenu:
            // Here are function that prepares Console for printing menu	 
            ConsoleManager::setTextVisible();        
            ConsoleManager::setCursorVisible();      
            View::inGameMenu_m();
            // value of 22 = the exact line number on Console for selection of 1st option from menu                   
            ConsoleManager::cursorNavigation(22, 4);  
            executeInGameMenuOption(m_gameOngoing);
            break;
        case ActionType::QuitGame:
            m_gameOngoing = false;
            break;
	}
}

bool Game::confirmDiscardItem() {
    View::showDiscardConfirmationMessage();
    ConsoleManager::cursorNavigation(8, 2);
    int option = ConsoleManager::getOptionIndex();
    if (option==1) {
        return true;
    }
    else {
        return false;
    }
}

void Game::handleItemDiscard(Item* item, int itemIndex) {
View::displayItemInfo(item);
        if (confirmDiscardItem()) {
            m_player->discardItem(item, itemIndex);
        }
}

void Game::browseInventory() {
    std::vector<Item*> items = m_player->getInventoryItemList();
    View::listInventoryItems(items);
    int short totalOptions = m_player->getTotalNumberOfItems() + 1; // adds '1' for option 'Leave Inventory' without action
    ConsoleManager::cursorNavigation(3, totalOptions);
    int selectedOption = ConsoleManager::getOptionIndex();

    // if statement to check if user haven't choose option 'Leave Inventory'
    if (selectedOption < totalOptions) {
        selectedOption--;    // removing the value selectedOption  to real index of item in itemList in inventory
        int realItemIndex = selectedOption;
        manageItemInteraction(realItemIndex);
    }
}
// todo const item* get and parameter const item* 
void Game::manageItemInteraction(int itemIndex) {
    Item* selectedItem = m_player->selectItem(itemIndex);
    View::displayItemInfo(selectedItem);
    View::displayItemActions(selectedItem);
    ConsoleManager::cursorNavigation(6, 4);
    executeItemAction(selectedItem, itemIndex);
}

// ------**Execution of Menus**------
void Game::executeInGameMenuOption(bool &gameOngoing) {
    int option = ConsoleManager::getOptionIndex();		// Gets option to perform based on cursor Position
    system ("cls");
    switch (option) {
    case 1:
        std::cout << "\nPersonal Stats\n" << std::endl;
        system ("pause");
        break;
    case 2:
        accessInventory();
        break;
    case 3:     // Leave menu - hide options only map displayed
        break;
    case 4:
        gameOngoing = false;
        return;
    }
    system ("cls");
}


void Game::executeInventoryOption(){
    int option = ConsoleManager::getOptionIndex();
    std::vector<Item*> items = m_player->getInventoryItemList();
    system ("cls");
    switch (option) {
    case 1:
        m_player->drinkPotion();
        break;
    case 2: {
        browseInventory();
        break;
    }
    case 3:        // The Inventory will be close due to selection of option 'Leave Inventory' 
        break;
    }
}

void Game::executeItemAction(Item* item, int itemIndex) {
    int option = ConsoleManager::getOptionIndex();
    system("cls");
    switch(option) {
    case 1:		// todo separate function
        if (item->getCategory()=="Potion") {
            m_player->drinkPotion();
        }
        if (item->getCategory()=="Armor" || item->getCategory()=="Weapon") {
            // equip
        }
        break;
    case 2:
	handleItemDiscard(item, itemIndex);        
            system("cls");
        break;
    case 3:   // Back to inventory
        break;
    case 4:   // Leave inventory
        return;
    }
    //browseInventory();
    accessInventory();
}

void Game::accessInventory() {
    int totalPotions = m_player->getNumberOfPotions();
    View::displayInventory_m(totalPotions);
    ConsoleManager::cursorNavigation(4, 3);
    executeInventoryOption();
}
