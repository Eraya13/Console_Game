#pragma once
#include <vector>
#include <fstream>
#include <array>
#include "Room.h"

/**
 * @class Map
 * @brief Represents the overall game map containing multiple locations, each consisting of several rooms.
 * The map is generated by reading a text file (`LocationNames.txt`), which contains the names of directories.
 * Each directory corresponds to a location, and within each location's folder, there are text files representing individual rooms. */
class Map {
private:
    std::vector<std::vector<Room*>> m_map;
    Room* m_room;                                   // sem se ulozi konkretni roomka
    std::array<std::string, 10> m_dir_location;     // nazvy slozek s lokacemi
    static const std::string MAP_FOLDER; ///< The relative path to the folder containing map files.

    /**
    * @brief Creates the map by reading location names and generating rooms.
    * This function reads the location names from a file and creates rooms for each location.
    *
    * @note This function is called during the construction of the `Map` object. */
    void createMap(std::string path_locationNames);

    /**
    * @brief Creates rooms based on the location names and room files.
    * This function populates the map with rooms for each location based on the files read. */
    void createRooms();
    
    /**
    * @brief Reads a room file and verifies if it can be opened.
    * @param path The path to the room file.
    * @return Returns true if the file can be opened; otherwise, returns false. */
    bool readRoomFile(std::string path);

    /**
    * @brief Reads location names from a file and populates the map with locations.
    * @param path_locationNames The path to the file containing location names.
    * @return Returns true if the file was successfully read; otherwise, returns false. */
    bool readLocationNames(std::string const path_locationNames);
public:
    /**
    * @brief Constructs a Map object by loading text file (`LocationNames.txt`) with location names and creating rooms.
    * @param fileName Name of the file that contains the list of location names. */
    Map(std::string fileName);

    /**
    * @brief Retrieves a pointer to a specific Room within a location.
    * @param location Index of the location.
    * @param index Index of the room within the location.
    * @return Pointer to the specified Room. */
    Room* getRoom(int location, int index) const;
    static const std::string LOCATION_NAMES; ///< The name of the file containing location names.

    /**
    * @brief Handles the process of changing rooms (to be implemented).
    */
    // changeRoom()
};

