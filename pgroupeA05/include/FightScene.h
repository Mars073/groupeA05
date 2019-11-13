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
#include "BtnMagic.h"
#include "BtnObject.h"
#include "Cooldown.h"
#include "string.h"
#include "DrawableMonster.h"
#include "Resources.h"
#include "Util/FontsManager.h"


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
        //Bar of Fight
        Bar* getBar()const;
        Bar* getBarMp()const;
        Bar* getBarMonsterLife()const;
        sf::Texture getTextureBackGroud()const;
        void setTextureBackGroud(std::string path);

        sf::Texture getSpriteBackGroud()const;
        void setSpriteBackGroud(std::string path);

        float getTimeEventIsNotActive()const;
        void setTimeEventIsNotActive(float newTime);

        void setNameMonster(std::string val){nameMonster = val;}

        void setSpriteMonster();

        void setSpritePlayer();

        void setText(std::string text);
        void setMonster();
        void setPlayer();
        void setStringText();
        void WriteText(std::string);











    protected:

    private:
        int activate;
        int secondWindowsActivate;
        bool isEventActive;
        bool isCooldown;
        float timeEventIsNotActive;
        sf::Clock clock;
        Player *player;
        Monster * monster;
        WindowsFight *fn;
        WindowsFight *fn2;
        WindowsFightInfo *fn3;
        std::string cc;

        std::vector<WindowsFight*>vectWindows;
        Bar *barLife;
        Bar *barMp;
        Bar *barMonsterLife;

        sf::Texture textureBackGroud;
        sf::Sprite sprintBackGroud;

        sf::Texture textureMonster;
        sf::Sprite spriteMonster;

        sf::Texture texturePlayer;
        sf::Sprite spritePlayer;
        std::string nameMonster;

        sf::Text textCombat;

        sf::Font police;
        bool isCurrentlyWrite;
        std::string textCurrentlyWrite;
        std::string textWhichMustBeWrite;
        int indexTextWhichMustBeWrite;

        //Manage the fight
        FightManager *fm;
        FontsManager *ft;


};

#endif // FightScene_H
