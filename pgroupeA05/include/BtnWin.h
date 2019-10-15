#ifndef BtnWin_H
#define BtnWin_H
#include <SFML/Graphics.hpp>
#include "string"
#include "iostream"
#include "vector"


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
        sf::RectangleShape getRect()const;
        void getNbBoutton();
        void ativate();
        void Desativate();
        void changeColorActivate();
        void changeColorDesactivate();
        std::vector<BtnWin*>getListButton()const;
        virtual void action();
        void Draw();
        bool getisActivate();
        void setIsActivate(bool val);
        std::string getDescription()const;
        void setDescription(std::string str);
        BtnWin(const BtnWin& c);
        sf::Text getText();
        void execute();



    protected:

    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        std::string Description;
        sf::Text text;
        sf::Font font;
        bool isActivate = false;
        std::vector<BtnWin*>ListButton;
        sf::RectangleShape rect;


};

#endif // BtnWin_H
