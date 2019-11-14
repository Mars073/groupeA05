#ifndef SCENE_H
#define SCENE_H

#include <string.h>
#include <SFML/Graphics.hpp>
#include "Util/FontsManager.h"
#include "Util/SoundsManager.h"
#include "Util/TexturesManager.h"

using namespace std;
using namespace sf;

class StrategyScene : public Drawable
{
    protected:
        Clock clock;
        FontsManager*   fm = FontsManager::getInstance();
        SoundsManager*  sm = SoundsManager::getInstance();
        TexturesManager*tm = TexturesManager::getInstance();

    public:
        StrategyScene();
        ~StrategyScene();
        bool controller = true;
        // /!\ crée une abstraction au niveau de la classe
        virtual void draw(RenderTarget&, RenderStates)const = 0;
        virtual void eventHandler(Event) = 0;

        // raccourcis scene <-> game
        RenderWindow* getWindow();
        void setScene(StrategyScene*) const;
        void gotoPreviousScene() const;

};

#endif // SCENE_H
