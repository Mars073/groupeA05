#ifndef MAPSCENE_H
#define MAPSCENE_H

#include "Scene.h"

class MapScene: public Scene
{
    private:

    public:
        MapScene();
        void draw();
        void eventHandler(Event);

};

#endif // MAPSCENE_H
