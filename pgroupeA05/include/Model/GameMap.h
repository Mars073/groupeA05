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
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Model/SingletonGame.h"
#include "Model/TileInfo.h"
#include "View/DrawablePlayer.h"
#include "View/Scenes/ConcreteStrategyFightScene.h"

using sf::Texture;
using sf::Sprite;
using sf::RenderWindow;
using sf::Clock;
using sf::Sound;
using sf::SoundBuffer;

/**
 * Implementation of a map for the game
 *
 * The map is a vector containing tiles, each of its tiles contains information describing it.
 * Maps can be imported from or a file or generated empty with the constructor.
 *
 */
class GameMap
{
    private:
        unsigned width;                     //!< The size of the side of the map
        unsigned world = 0;                 //!< ID of the world map
        vector<TileInfo> dataset;           //!< Tile's vector
        vector<int> random_teleporters;     //!< List of teleporters ID (holes) on the map
        Bestiary* beast;                    //!< List of monster available on the map
        Texture texture;                    //!< Texture sprise use to draw the map
        SoundsManager*  sm = SoundsManager::getInstance(); //!< Sound service
        Clock clock;                        //!< Clock for animation
    public:
        struct neighboursInfo               //!< Internal structure for easily use map
        {
            const TileInfo // Compass Declaration
                *N,
             *NO,  *NE,
            *O,      *E,
             *SO,  *SE,
                *S;
        };
        static const unsigned TILE_SIZE = 32;               //!< Size of tiles (drawing)
        static const unsigned TEXTURE_RANGE = 12;           //!< The X limite on texture file between floor and object
        static const unsigned GUID_RANDOM_TELEPORTER = 73;  //!< GameObject ID of teleporters on map
        static const unsigned GUID_DOORS = 131;             //!< GameObject ID of doors
        static const unsigned FLOOR_AGGRO = 4;              //!< Kind of floor where you can found monsters
        static const unsigned FLOOR_HIGH_AGGRO = 18;        //!< Kind of floor where you've more chance to found monters (high weeds)
        static const unsigned RATE_AGGRO = 5;               //!< Chance of aggression (%)
        static const unsigned RATE_HIGH_AGGRO = 20;         //!< Chance of aggression in weeds (%)

        GameMap(int = 64);                      //!< Basic constructor
        virtual ~GameMap();                     //!< Basic destructor
        bool loadFromFile(string);              //!< Generate map by file
        bool loadFromFileID(unsigned);          //!< Generate map by file ID
        void setTexture(const Texture& texture);//!< setter of Texture sprite
        Texture getTexture() const;             //!< getter of Texture sprite
        void spawn();                           //!< event when you load a new world
        void setWidth(int width);               //!< setter of map side
        unsigned getWidth() const;              //!< getter of map side
        void draw() const;                      //!< drawing method
        Vector2u tx2loc(int) const;             //!< Convert texture ID to texture location (on sprite)
        Vector2u ob2loc(int objectID) const;    //!< Convert object ID to texture location (on sprite)
        TileInfo xy2t(const Vector2f) const;    //!< Convert map location to TileInfo
        unsigned xy2i(const Vector2f) const;    //!< Convert map location to vector index
        Vector2f i2xy(const unsigned) const;    //!< Condex vector index to map location
        neighboursInfo getNeighboursInfo(const unsigned) const;         //!< Get neigbours of a tile (by id)
        void interact(DrawablePlayer&, const TileInfo*, GameMap&) const;//!< Interaction event between the player and objects on the map
};

#endif // GAMEMAP_H
