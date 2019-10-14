#ifndef WindowsFight_H
#define WindowsFight_H
#include "vector"
#include "BtnWin.h"
#include <SFML/Graphics.hpp>
#include "vector"



class WindowsFight
{
    public:
        WindowsFight(int positionX,int positionY,int tailleX,int tailleY);
        int getPositionX() const;
        int getPositionY() const;
        int getTailleX() const;
        int getTailleY()const;
        sf::RectangleShape getRect()const;
        std::vector<BtnWin*> getVect();
        void draw(sf::RenderWindow &rd);
        void activateButton(int index);
        int getNbBoutton();
        void ajouterBouton(BtnWin btn);
        void retirerBouton(int index);

        virtual ~WindowsFight();

    protected:

    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        int indexSelectionner;
        int activateIndex;
        std::vector<BtnWin*> vectorButton;
        sf::RectangleShape rect;



};

#endif // WindowsFight_H
