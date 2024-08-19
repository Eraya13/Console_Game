cmake_minimum_required(VERSION 3.16)
project(Game)

set(CMAKE_CXX_STANDARD 17)

include_directories(01_Enums)
include_directories(02_Entity)
include_directories(03_Map)
include_directories(04_Structs)
include_directories(099_Files_TXT)
include_directories(05_FrontEndClasses)
include_directories(Players_Classes)

add_executable (Game
#Enums
01_Enums/ActionType.h
01_Enums/Colors.h
01_Enums/TileType.h
02_Entity/IEntity.h

02_Entity/Entity.cpp 02_Entity/Entity.h
02_Entity/Enemy.cpp 02_Entity/Enemy.h
02_Entity/NPC.cpp 02_Entity/NPC.h
02_Entity/Item.cpp 02_Entity/Item.h
02_Entity/Weapon.cpp 02_Entity/Weapon.h
02_Entity/Armor.cpp 02_Entity/Armor.h
03_Map/Map.cpp 03_Map/Map.h
03_Map/Room.cpp 03_Map/Room.h
03_Map/Tile.cpp 03_Map/Tile.h
03_Map/EntityManager.cpp 03_Map/EntityManager.h
04_Structs/PositionStruct.h
05_FrontEndClasses/DisplayScreens.cpp 05_FrontEndClasses/DisplayScreens.h
05_FrontEndClasses/GUI.cpp 05_FrontEndClasses/GUI.h
Players_Classes/Controls.cpp Players_Classes/Controls.h
Players_Classes/Player.cpp Players_Classes/Player.h
DataFormatting.cpp DataFormatting.h
Game.cpp Game.h
GlobalVariables.h
ErrorLog.cpp ErrorLog.h
main.cpp
)

include(GNUInstallDirs)
install(TARGETS Game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
