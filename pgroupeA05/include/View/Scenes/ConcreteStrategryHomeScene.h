#ifndef HOMESCENE_H
#define HOMESCENE_H

#include "View/StrategyScene.h"

class ConcreteStrategyHomeScene: public StrategyScene
{
    private:
        const unsigned short int MENU_LENGTH = 3;
        const string menu[3] = {"PLAY", "CREDITS", "QUIT"};
        short int selected_id = 0;

    public:
        ConcreteStrategyHomeScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // HOMESCENE_H
