#ifndef FightScene_H
#define FightScene_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "WindowsFight.h"
#include "vector"
#include "iostream"
#include "View/StrategyScene.h"
#include "WindowsFightInfo.h"
#include "Player.h"
#include "Monster.h"
#include "Model/SingletonGame.h"
#include "Bar.h"


class FightScene: public StrategyScene
{
    public:
        FightScene();
        virtual ~FightScene();
        void fight();
        void draw(RenderTarget&,RenderStates) const override;
        void eventHandler(Event ev);
        //Get and setter
        std::vector<WindowsFight*>getVectWindows()const;
        void setActivate(int activate);
        void setFightManager(FightManager *fm);
        FightManager* getFightManager()const;
        Bar* getBar()const;
        Bar* getBarMp()const;
        Bar* getBarMonsterLife()const;





    protected:

    private:
        int activate;
        Player *player;
        Monster * monster;
        WindowsFight *fn;
        WindowsFight *fn2;
        WindowsFightInfo *fn3;
        std::vector<WindowsFight*>vectWindows;
        Bar *barLife;
        Bar *barMp;
        Bar *barMonsterLife;
        //Manage the fight
        FightManager *fm;

};

#endif // FightScene_H
