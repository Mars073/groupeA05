#ifndef MAPSCENE_H
#define MAPSCENE_H

#include<thread>
#include<chrono>
#include "View/StrategyScene.h"
#include "View/Scenes/ConcreteStrategyMenuScene.h"
#include "View/Scenes/WindowStatus.h"
#include "Model/GameMap.h"
#include "View/DrawablePlayer.h"
class ConcreteStrategyMapScene: public StrategyScene
{
    private:
        GameMap gmap;
        DrawablePlayer player;
        void timeoutFX(unsigned ms = 200);
        bool isFXIntro = false;
        bool isFXFight = false;
        void drawFXIntro(RenderTarget&) const;
        void drawFXFight(RenderTarget&) const;

    public:
        ConcreteStrategyMapScene();
        void playFXIntro();
        void playFXFight();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);
        void setCamera(RenderTarget&, float, float) const;
        void setCamera(RenderTarget&, Vector2f) const;
};

#endif // MAPSCENE_H
