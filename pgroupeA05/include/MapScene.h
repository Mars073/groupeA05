#ifndef MAPSCENE_H
#define MAPSCENE_H

#include "Scene.h"
#include "GameMap.h"

class MapScene: public Scene
{
    private:
        GameMap gmap;

    public:
        MapScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // MAPSCENE_H
