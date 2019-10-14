#ifndef FightScene_H
#define FightScene_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "WindowsFight.h"
#include "vector"
#include "iostream"
#include "Scene.h"
#include "WindowsFight.h"


class FightScene: public Scene
{
    public:
        FightScene();
        virtual ~FightScene();
        void fight();
        void draw(RenderTarget&,RenderStates) const override;
        void eventHandler(Event ev);
        void setActivate(int activate);

    protected:

    private:
        int activate;
        WindowsFight *fn;
};

#endif // FightScene_H
