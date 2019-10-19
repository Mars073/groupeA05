#ifndef BtnWin_H
#define BtnWin_H
#include <SFML/Graphics.hpp>
#include "string"
#include "iostream"
#include "vector"
#include "WindowsFight.h"


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

        void setPositionX(int pos);
        void setPositionY(int pos);
        void setTailleX(int pos);
        void setTailleY(int pos);


        sf::RectangleShape getRect()const;
        void getNbBoutton();
        void ativate();
        void Desativate();
        void changeColorActivate();
        void changeColorDesactivate();

        std::vector<BtnWin*>getListButton()const;
        void AddButtonInWindows(WindowsFight fn*);
        void AddButton(BtnWin btn*);
        virtual void action();
        void Draw();
        bool getisActivate();
        sf::Text text;
        void setIsActivate(bool val);
        std::string getTextButton();
        std::string getDescription()const;
        void setDescription(std::string str);
        BtnWin(BtnWin const& c);
        sf::Text getText();
        void execute();



    protected:

    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        std::string Description;
        std::string nomText;

        sf::Font font;
        bool isActivate = false;
        std::vector<BtnWin*>ListButton;
        sf::RectangleShape rect;


};

#endif // BtnWin_H
