#ifndef SCENE_H
#define SCENE_H

#include <string.h>
#include <SFML/Graphics.hpp>
#include "Resources.h"

using namespace std;
using namespace sf;

class StrategyScene : public Drawable
{
    private:

    public:
        StrategyScene();
        ~StrategyScene();
        bool controller = true;
        // /!\ crée une abstraction au niveau de la classe
        virtual void draw(RenderTarget&, RenderStates)const = 0;
        virtual void eventHandler(Event) = 0;

        // raccourcis scene <-> game
        RenderWindow* getWindow();
        void setScene(StrategyScene*);
        void gotoPreviousScene();

};

#endif // SCENE_H
