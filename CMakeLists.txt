cmake_minimum_required(VERSION 3.0.0)
project(Game VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(Game
01_Enums/ActionType.h
01_Enums/Colors.h
01_Enums/TileType.h
02_Entity/Enemy.cpp
03_Map/Map.cpp
03_Map/Room.cpp
03_Map/Tile.cpp
FrontEndClasses/DisplayScreens.cpp
FrontEndClasses/GUI.cpp
Players_Classes/Controls.cpp
Players_Classes/Player.cpp
Players_Classes/PositionStruct.h
DataFormatting.cpp
Game.cpp
GlobalVariables.h
ErrorLog.cpp
main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
