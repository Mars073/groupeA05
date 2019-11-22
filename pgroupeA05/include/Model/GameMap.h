// *** ADDED BY HEADER FIXUP ***
#include <ctime>
#include <istream>
// *** END ***
#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Model/SingletonGame.h>
#include <Model/TileInfo.h>
#include <View/DrawablePlayer.h>
#include <FightScene.h>

using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;
using sf::Clock;
using sf::Sound;
using sf::SoundBuffer;


class GameMap
{
    private:
        unsigned width;
        unsigned world = 0;
        vector<TileInfo> dataset;
        vector<int> random_teleporters;
        Bestiary* beast;
        Texture texture;
        SoundBuffer buffer;
        Sound sound;
        Clock clock;
    public:
        struct neighboursInfo
        {
            const TileInfo // Compass Declaration
                *N,
             *NO,  *NE,
            *O,      *E,
             *SO,  *SE,
                *S;
        };
        static const unsigned TILE_SIZE = 32;
        static const unsigned TEXTURE_RANGE = 12;
        static const unsigned GUID_RANDOM_TELEPORTER = 73;
        static const unsigned GUID_DOORS = 131;
        static const unsigned FLOOR_AGGRO = 4;
        static const unsigned FLOOR_HIGH_AGGRO = 18;
        static const unsigned RATE_AGGRO = 5;//%
        static const unsigned RATE_HIGH_AGGRO = 20;//%

        GameMap(int = 64);
        virtual ~GameMap();
        bool loadFromFile(string);
        bool loadFromFileID(unsigned);
        void setTexture(const Texture& texture);
        Texture getTexture() const;
        void spawn();
        void setWidth(int width);
        unsigned getWidth() const;
        void draw() const;
        Vector2u tx2loc(int) const;
        Vector2u ob2loc(int objectID) const;
        TileInfo xy2t(const Vector2f) const;
        unsigned xy2i(const Vector2f) const;
        Vector2f i2xy(const unsigned) const;
        neighboursInfo getNeighboursInfo(const unsigned) const;
        void interact(DrawablePlayer&, const TileInfo*, GameMap&) const;
};

#endif // GAMEMAP_H
