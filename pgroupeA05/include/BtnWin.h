#ifndef BtnWin_H
#define BtnWin_H
#include <SFML/Graphics.hpp>
#include "string"
#include "iostream"


class BtnWin
{
    public:
        BtnWin(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
        virtual ~BtnWin();
        int getPositionX() const;
        int getPositionY() const;
        int getTailleX() const;
        int getTailleY()const;
        sf::RectangleShape getRect()const;
        void getNbBoutton();
        void ativate();
        void Desativate();
        void changeColorActivate();
        void changeColorDesactivate();
        virtual void action();
        void Draw();
        bool getisActivate();
        void setIsActivate(bool val);
        sf::Text getText();
        void execute();



    protected:

    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        sf::Text text;
        sf::Font font;
        bool isActivate = false;
        sf::RectangleShape rect;
        IstrategyBtn *strat;

};

#endif // BtnWin_H
