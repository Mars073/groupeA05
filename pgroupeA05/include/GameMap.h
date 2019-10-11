#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>
#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "TileInfo.h"

using namespace std;
using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;
using sf::Clock;


class GameMap
{
    private:
        struct neighboursInfo
        {
            const TileInfo // Compass Declaration
                *N,
             *NO,  *NE,
            *O,      *E,
             *SO,  *SE,
                *S;
        };
        int width;
        vector<TileInfo> dataset;
        Texture texture;
        Clock clock;
    public:
        const int TILE_SIZE = 32;
        const int TEXTURE_RANGE = 12;
        GameMap();
        GameMap(int);
        bool loadFromFile(string);
        void setWidth(int width);
        void draw() const;
        Vector2u tx2loc(int) const;
        neighboursInfo getNeighboursInfo(const int) const;
};

#endif // GAMEMAP_H
