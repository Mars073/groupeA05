#include "Model/TileInfo.h"

TileInfo::TileInfo(const int index = 0, long int data = 0):
    INDEX(index),
    FLOOR_ID(data >> 10),
    GAMEOBJECT_ID((data >> 2) & 255),
    COLLISION(data & 1),
    TOPMOST(data & 2)
{
    // ctor
}

Vector2u TileInfo::getPosition(const unsigned map_side) const
{
    Vector2u tmp(
        INDEX % map_side,
        INDEX / map_side // div int => math floor
    );
    return tmp;
}
