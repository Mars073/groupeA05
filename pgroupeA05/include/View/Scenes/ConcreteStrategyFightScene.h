#ifndef CONCRETESTRATEGYFIGHTSCENE_H
#define CONCRETESTRATEGYFIGHTSCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "View/Components/WindowsFight.h"
#include "vector"
#include "iostream"
#include "View/StrategyScene.h"
#include "View/Components/WindowsFightInfo.h"
#include "Model/Player.h"
#include "Model/Monster.h"
#include "Model/SingletonGame.h"
#include "View/Components/Bar.h"
#include "View/Components/BtnMagic.h"
#include "View/Components/BtnObject.h"
#include "View/Components/BtnDefend.h"
#include "string.h"
#include "View/DrawableMonster.h"
#include "Util/FontsManager.h"
#include "View/Components/Panel.h"



using sf::Thread;

class ConcreteStrategyFightScene: public StrategyScene
{
    public:
        ConcreteStrategyFightScene();
        virtual ~ConcreteStrategyFightScene();
        void fight();
        void draw(RenderTarget&,RenderStates) const override;
        void eventHandler(Event ev);
        //Get and setter
        std::vector<WindowsFight*> getVectWindows() const;
        void setActivate(int activate);
        void setFightManager(FightManager *fm);
        FightManager* getFightManager()const;

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
        void WriteText();

        int GetIndexNbButtonDisplay()const{return indexNbButtonDisplay;};
        int GetlimiteNbButtonDisplay()const{return limiteNbButtonDisplay;};
        int GetNbButtonDisplay()const{return NbButtonDisplay;};

        void SetIndexNbButtonDisplay(int val){indexNbButtonDisplay = val;};
        void SetLimiteNbButtonDisplay(int val){limiteNbButtonDisplay = val;};
        void SetNbButtonDisplay(int val){NbButtonDisplay = val;};

        void VerifNbDisplayButton();

        void CalculTailleBar();
        void CalculVfxAnimation(int indexX,int indexY,bool isAttack);
        void MakeAnimation(int,int);




















    protected:

    private:
        bool* kill_sig;
        //index for know if a button is select
        int activate;
        //index for know if a windows is select
        int secondWindowsActivate;
        bool isEventActive;
        bool isCooldown;
        float timeEventIsNotActive;
        //clock enable to know the time
        sf::Clock clock;
        //Player in ConcreteStrategyFightScene
        Player *player;
        //Monster in ConcreteStrategyFightScene
        Monster * monster;
        //Windows contain button
        WindowsFight *fn;
        //Windows contain button
        WindowsFight *fn2;
        //Windows contain button
        WindowsFightInfo *fn3;
        std::string cc;
        //vector contain differents windows
        std::vector<WindowsFight*> vectWindows;
        //Bar of player
        Bar barLife;
        //Bar of  Mp
        Bar barMp;
        //Bar of monsterLife
        Bar barMonsterLife;
        //Texture of the scene
        sf::Texture textureBackGroud;
        sf::Sprite sprintBackGroud;

        sf::Texture textureMonster;
        sf::Sprite spriteMonster;

        sf::Texture texturePlayer;
        sf::Sprite spritePlayer;

        sf::Texture textureVfx;
        sf::Sprite spriteVfx;


        sf::Texture textureTest;
        sf::Sprite spTest;
        //Text of fight
        std::string nameMonster;
        sf::Text textCombat;
        //Police use for the text displayed
        sf::Font police;
        //variable that check if the text of fight is currently write
        bool isCurrentlyWrite;
        //Text is currently write in text combat
        std::string textCurrentlyWrite;
        //Text is currently write in text combat
        std::string textWhichMustBeWrite;
        int indexTextWhichMustBeWrite;

        //Manage the fight
        FightManager *fm;
        //thread
        Thread* thd = nullptr;

        //limite the number of button displayed
        int indexNbButtonDisplay;
        int limiteNbButtonDisplay;
        int NbButtonDisplay;
        //DrawableBattleCharacter dbw;
        //index of vfx
        int indexXVfx;
        int indexYVfx;
        bool isAnimVfx;

        bool isBtnisAttack;



};

#endif // CONCRETESTRATEGYFIGHTSCENE_H
