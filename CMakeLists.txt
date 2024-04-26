cmake_minimum_required(VERSION 3.26)
project(Projekt_Save_The_Princess)

set(CMAKE_CXX_STANDARD 17)

include_directories(01_Enums)
include_directories(02_Entity)
include_directories(03_Map)
include_directories(04_Structs)
include_directories(099_Files_TXT)
include_directories(05_FrontEndClasses)
include_directories(Players_Classes)

add_executable (Game
01_Enums/ActionType.h
01_Enums/Colors.h
01_Enums/TileType.h
02_Entity/IEntity.h
02_Entity/Entity.cpp
02_Entity/Enemy.cpp
02_Entity/NPC.cpp
03_Map/Map.cpp
03_Map/Room.cpp
03_Map/Tile.cpp
03_Map/EntityManager.cpp
04_Structs/PositionStruct.h
05_FrontEndClasses/DisplayScreens.cpp
05_FrontEndClasses/GUI.cpp
Players_Classes/Controls.cpp
Players_Classes/Player.cpp
DataFormatting.cpp
Game.cpp
GlobalVariables.h
ErrorLog.cpp
main.cpp)