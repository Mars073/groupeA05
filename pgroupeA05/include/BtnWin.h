#ifndef BtnWin_H
#define BtnWin_H
#include <SFML/Graphics.hpp>
#include "string"
#include "iostream"
#include "vector"
#include "Player.h"
#include "Monster.h"
#include "FightManager.h"



class BtnWin
{
    public:
        BtnWin(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
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
        void getNbBoutton();
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
        bool getisActivate();
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



    protected:

    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        std::string Description;
        std::string nomText;
        bool isButtonMenu;

        sf::Font font;
        bool isActivate = false;
        std::vector<BtnWin*>ListButton;
        sf::RectangleShape rect;
        /*Fight manager come of FightScene.
        don't destruct here because he wiil destruct in fightManager*/
        FightManager *fm;


};

#endif // BtnWin_H
