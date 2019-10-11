#ifndef TILEINFO_H
#define TILEINFO_H

#include <SFML/Graphics.hpp>
using sf::Vector2u;

class TileInfo
{
    private:
    public:
        const int INDEX;
        const int FLOOR_ID;
        const int GAMEOBJECT_ID;
        bool COLLISION;
        bool TOPMOST;
        TileInfo(const int, long int);
        Vector2u getPosition(const int);
};

#endif // TILEINFO_H
