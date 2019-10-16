#ifndef MAPSCENE_H
#define MAPSCENE_H

#include<thread>
#include<chrono>
#include "Scene.h"
#include "GameMap.h"
#include "Player.h"

class MapScene: public Scene
{
    private:
        Clock fxClock;
        GameMap gmap;
        Player player;
        void timeoutFXIntro();
        bool isFXIntro = false;

    public:
        MapScene();
        void playFXIntro();
        void drawFXIntro(RenderTarget&) const;
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // MAPSCENE_H
