#ifndef TILEINFO_H
#define TILEINFO_H

#include <SFML/Graphics.hpp>
using sf::Vector2u;

class TileInfo
{
    private:
    public:
        const unsigned INDEX;
        const unsigned FLOOR_ID;
        const unsigned GAMEOBJECT_ID;
        bool COLLISION;
        bool TOPMOST;
        TileInfo(const int, long int);
        Vector2u getPosition(const unsigned) const;
};

#endif // TILEINFO_H
