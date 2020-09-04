#ifndef TILEINFO_H
#define TILEINFO_H

#include "SFML/Graphics.hpp"
using sf::Vector2u;

/*
 * Implement a Tile structure with different data like the object or the collision
 */
class TileInfo
{
    private:
    public:
        const unsigned INDEX;           //!< Index of the Tile
        const unsigned FLOOR_ID;        //!< Floor ID on this tile
        const unsigned GAMEOBJECT_ID;   //!< Object ID on this tile
        bool COLLISION;                 //!< Define if this tile have collision
        bool TOPMOST;                   //!< Define if the object on this tile is hover the player
        TileInfo(const int, long int);  //!< Basic constructor
        Vector2u getPosition(const unsigned) const;//!< Define the position of the tile with the map size
};

#endif // TILEINFO_H
