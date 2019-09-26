#ifndef GAMEMAP_H
#define GAMEMAP_H

#include<Graphics.hpp>

using namespace sf;

class GameMap
{
    private:
        int *dataset;
        Texture texture;
    public:
        GameMap();
        ~GameMap();
        int width = 8;
        void setTexture(Texture);
        void draw();
};

#endif // GAMEMAP_H
