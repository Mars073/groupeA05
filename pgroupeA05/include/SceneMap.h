#ifndef SCENEMAP_H
#define SCENEMAP_H

#include<Scene.h>
#include<GameMap.h>

class SceneMap: public Scene
{
    private:
        GameMap gmap;

    public:
        SceneMap();
        void draw();
        void eventHandler(sf::Event);
};

#endif // SCENEMAP_H
