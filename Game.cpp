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
    m_player = new Player("Derien", 100, 40);
	createMap("LocationsNames.txt");
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

// provede akci - na základě hodnoty, která se vrátí z decideActionType()
void Game::performAction(ActionType action) {
	bool changeRoomYesOrNo = false;		// default value - no travel is required right away
	switch (action) {
		case ActionType::Movement:
			// It creates a new position according to WASD
            m_playerController->createNextPosition();
			// analyze if movement is possible to the next position 
            m_playerController->analyzeAperformNextPosition(changeRoomYesOrNo);
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

// ------**Execution of Menus**------
// **Provedení vybraných možností z InGameMenu
void Game::executeInGameMenuOption(bool &gameOngoing) {
    int option = ConsoleManager::getOptionIndex();		// Gets option to perform based on cursor Position
    system ("cls");
    switch (option) {
    case 1:
        std::cout << "\nPersonal Stats\n" << std::endl;
        system ("pause");
        break;
    case 2: {
        accessInventory();
        break;
    }
    case 3:
        std::cout << "\nExit Menu\n"  << std::endl;
        system ("pause");
        break;
    case 4:
        std::cout << "\nLeave Game\n" << std::endl; // debug print
        gameOngoing = false;
        system ("pause");
        break;
    default:
        std::cout << "\nError - no option found\n" << std::endl; // todo ErorLog
        system ("pause");
    }
    system ("cls");
}


void Game::executeInventoryOption(){
    int option = ConsoleManager::getOptionIndex();
    std::vector<Item*> items = m_player->getInventoryItemList();
    system ("cls");
    switch (option) {
    case 1:
        // Item* findHealthPotion(); -- inventory musí najít
        break;
    case 2: {
        View::listInventoryItems(items);
        int short totalOptions = m_player->getTotalNumberOfItems() + 1; // adds '1' for option 'Leave Inventory' without action
        ConsoleManager::cursorNavigation(3, totalOptions);
        int realItemIndex = ConsoleManager::getOptionIndex();

        // if statement to check if user haven't choose option 'Leave Inventory'
        if (realItemIndex < totalOptions) {
            realItemIndex--;    // úprava na reálné indexy (od 0)
            Item* selectedItem = m_player->selectItem(realItemIndex);
            View::displayItem(selectedItem);
            ConsoleManager::cursorNavigation(5, 3);
            executeItemAction(selectedItem, realItemIndex);
        }
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
    case 1:
        if (item->getCategory()=="Potion") {
            // drinkPotion
        }
        if (item->getCategory()=="Armor" || item->getCategory()=="Weapon") {
            // equip
        }
        break;
    case 2:
        m_player->discardItem(item, itemIndex);
        break;
    case 3:   // Back to inventory
        // action to display list of items again
	break;
    }
}

void Game::accessInventory() {
    int totalPotions = m_player->getNumberOfPotions();
    View::Inventory_m(totalPotions);
    ConsoleManager::cursorNavigation(4, 3);
    executeInventoryOption();
}
