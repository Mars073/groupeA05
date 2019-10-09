#include "TileInfo.h"

TileInfo::TileInfo(const int index, long int data):
    INDEX(index),
    COLLISION(data & 1),
    TOPMOST(data & 2),
    GAMEOBJECT_ID((data >> 2) & 127),
    FLOOR_ID(data >> 9)
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
