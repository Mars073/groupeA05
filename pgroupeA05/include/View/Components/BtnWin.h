#ifndef BtnWin_H
#define BtnWin_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Model/Player.h"
#include "Model/Monster.h"
#include "Model/FightManager.h"



class BtnWin
{
    public:
        BtnWin(int positionX = 0,int positionY =0,int tailleX = 0,int tailleY =0,std::string textButton="");
        BtnWin(int positionX,int positionY,int tailleX,int tailleY,std::string textButton,std::string Description);

        virtual ~BtnWin();
        int getPositionX() const;
        int getPositionY() const;
        int getTailleX() const;
        int getTailleY()const;
        FightManager* getFm();
        std::string getNomText() const;

        void setPositionX(int pos);
        void setPositionY(int pos);
        void setTailleX(int pos);
        void setTailleY(int pos);
        void setFm(FightManager *fmNew);
        void setNomText(std::string nomText);



        sf::RectangleShape getRect()const;
        void getNbBoutton()const;
        void ativate();
        void Desativate();
        void changeColorActivate();
        void changeColorDesactivate();

        std::vector<BtnWin*>getListButton();
//        void AddButtonInWindows(WindowsFight fn*);
        void AddButton(BtnWin *btn);
        bool getIsMenuBoutton()const;
        void setIsMenuBoutton(bool val);

        virtual void action();
        void Draw();
        bool getisActivate()const;
        sf::Text text;
        void setIsActivate(bool val);
        std::string getTextButton();
        virtual std::string getDescription();
        void setDescription(std::string str);
        BtnWin(BtnWin const& c);
        sf::Text getText();
        void execute();

        bool operator==(const BtnWin a);
        bool equals(const BtnWin b);
        bool equals(BtnWin* b);

        int getPosButtonAction()const{return posButtonAction;};
        int getNbBoutonDisplay()const{return nbBoutonDisplay;};

        void setPosButtonAction(int val){posButtonAction = val;};
        void setNbBoutonDisplay(int val){nbBoutonDisplay = val;};

        sf::Texture getVfxTexture(){return vfxTexture;};
        void setVfxTexture(std::string nom = "hit");

        bool getIsAttack()const{return isAttack;};
        void setIsAttack(bool val){isAttack = val;}
        BtnWin& operator=(const BtnWin& other);



    protected:

    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        std::string Description;
        std::string nomText;
        bool isButtonMenu;
        int posButtonAction;
        int nbBoutonDisplay;

        sf::Font font;
        bool isActivate = false;
        std::vector<BtnWin*>ListButton;
        sf::RectangleShape rect;
        /*Fight manager come of FightScene.
        don't destruct here because he wiil destruct in fightManager*/
        FightManager *fm;
        sf::Texture vfxTexture;
        bool isAttack;


};

#endif // BtnWin_H
