#ifndef FightScene_H
#define FightScene_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "WindowsFight.h"
#include "vector"
#include "iostream"
#include "Scene.h"
#include "WindowsFightInfo.h"


class FightScene: public Scene
{
    public:
        FightScene();
        virtual ~FightScene();
        void fight();
        void draw(RenderTarget&,RenderStates) const override;
        void eventHandler(Event ev);
        //Get and setter
        std::vector<WindowsFight*>getVectWindows();
        void setActivate(int activate);



    protected:

    private:
        int activate;
        WindowsFight *fn;
        WindowsFightInfo *fn2;
        WindowsFightInfo *fn3;
        std::vector<WindowsFight*>vectWindows;

};

#endif // FightScene_H
