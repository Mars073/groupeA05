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

class GameMap
{
    private:
        int width;
        vector<TileInfo> dataset;
        Texture texture;
    public:
        const int TILE_SIZE = 32;
        const int TEXTURE_RANGE = 12;
        GameMap();
        GameMap(int);
        bool loadFromFile(string);
        void setWidth(int width);
        void draw() const;
        Vector2u tx2loc(int) const;
        vector<TileInfo> getNeighboursInfo(const int) const;
};

#endif // GAMEMAP_H
