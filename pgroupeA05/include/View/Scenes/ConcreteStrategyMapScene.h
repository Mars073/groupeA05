#ifndef MAPSCENE_H
#define MAPSCENE_H

#include "View/StrategyScene.h"
#include "View/Scenes/ConcreteStrategyMenuScene.h"
#include "Model/GameMap.h"
#include "View/DrawablePlayer.h"

class ConcreteStrategyMapScene: public StrategyScene
{
    private:
        GameMap gmap;
        DrawablePlayer player;
        void timeoutFXIntro();
        bool isFXIntro = false;
        Thread* thFXIntro = nullptr;

    public:
        ConcreteStrategyMapScene();
        virtual ~ConcreteStrategyMapScene();
        void playFXIntro();
        void drawFXIntro(RenderTarget&) const;
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);
        void setCamera(RenderTarget&, float, float) const;
        void setCamera(RenderTarget&, Vector2f) const;
};

#endif // MAPSCENE_H
