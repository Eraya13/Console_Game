#pragma once

enum class TileType {
    // non-entity:
    GRASS = '.',
    WALL = '#',
    PORTAL = 'O',
    HOME = 'H',
    // entity:
    PLAYER = 'P',
    NPC = 'N',
    ENEMY = 'E',
    ITEM = 'I',
};