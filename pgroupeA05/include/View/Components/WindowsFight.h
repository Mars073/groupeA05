#ifndef WindowsFight_H
#define WindowsFight_H
#include "vector"
#include <SFML/Graphics.hpp>
#include "vector"
#include "FightManager.h"
#include "string"
#include "btnAttack.h"



class WindowsFight
{
    public:
        WindowsFight(int positionX = 0,int positionY = 0,int tailleX=0,int tailleY =0);
        //Getter and setter
        int getPositionX() const;
        int getPositionY() const;
        int getTailleX() const;
        int getTailleY()const;
        void setFm(FightManager *fm);
        sf::RectangleShape getRect()const;

        std::vector<BtnWin*> getVect()const;
        int getNbBoutton();
        //CRUD method for Button
        void addButton(BtnWin *btn);
        void removeButton(BtnWin btnRemove);
        void removeButton(int index);

        void draw(sf::RenderWindow &rd);
        void activateButton(int index);


        void retirerBouton(int index);
        //Clear button in Windows
        void ClearWindows();
        WindowsFight& operator=(const WindowsFight& rhs);
        WindowsFight(const WindowsFight& other);



        virtual ~WindowsFight();

    protected:
        sf::RectangleShape rect;
    private:
        int positionX;
        int positionY;
        int tailleX;
        int tailleY;
        int indexSelectionner;
        int activateIndex;
        std::vector<BtnWin*> vectorButton;



        FightManager *fm;




};

#endif // WindowsFight_H
