#include "TileInfo.h"

TileInfo::TileInfo(const int index = -1, long int data = 1):
    INDEX(index),
    FLOOR_ID(data >> 10),
    GAMEOBJECT_ID((data >> 2) & 255),
    COLLISION(data & 1),
    TOPMOST(data & 2)
{
    // ctor
}

Vector2u TileInfo::getPosition(const int map_side)
{
    Vector2u tmp(
        INDEX % map_side,
        INDEX / map_side // div int => math floor
    );
    return tmp;
}
