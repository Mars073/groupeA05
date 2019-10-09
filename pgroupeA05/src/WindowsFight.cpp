#include "WindowsFight.h"
#include "BtnWin.h"
#include "iostream"
#include "btnAttack.h"



WindowsFight::WindowsFight(int positionX,int positionY,int tailleX,int tailleY)
{
    this->rect.setPosition(sf::Vector2f(positionX,positionY));
    this->rect.setSize(sf::Vector2f(tailleX,tailleY));
    this->rect.setOutlineThickness(5);
    this->rect.setOutlineColor(sf::Color(0,200,0));
    this->rect.setFillColor(sf::Color(255,0,0));
    this->indexSelectionner = 0;
    btnAttack *btn = new btnAttack(positionX,positionY,80,50,"attaquer");
    btnAttack *btnMagie = new btnAttack(positionX,positionY+50,80,50,"Magie");
    btnAttack *btnObjet = new btnAttack(positionX,positionY+100,80,50,"Objet");


    this->vectorButton.push_back(btn);
    this->vectorButton.push_back(btnMagie);
    this->vectorButton.push_back(btnObjet);

}

WindowsFight::~WindowsFight()
{
    //dtor
}
int WindowsFight::getPositionX() const
{
    return positionX;
}
int WindowsFight::getPositionY()const
{
    return positionY;
}
int WindowsFight::getTailleX()const
{
    return tailleX;
}
int WindowsFight::getTailleY()const
{
    return tailleY;
}
sf::RectangleShape WindowsFight::getRect()const
{
    return rect;
}
void WindowsFight::draw(sf::RenderWindow &rd)
{
    rd.draw(rect);

}
std::vector<BtnWin*> WindowsFight::getVect()
{
    return vectorButton;
}
void WindowsFight::activateButton(int &index)
{
    if(index < 0)
    {
        index = vectorButton.size()-1;
    }
    else if(index > vectorButton.size()-1)
    {
        index = 0;
    }
    for(int i = 0;i < vectorButton.size()-1;i++)
    {
        vectorButton.at(i)->changeColorDesactivate();
        vectorButton.at(i)->Desativate();
    }
    vectorButton.at(index)->changeColorActivate();
    vectorButton.at(index)->ativate();
}
int WindowsFight::getNbBoutton()
{
    return (vectorButton.size()-1);
}
void WindowsFight::ajouterBouton(BtnWin btn)
{
    vectorButton.push_back(&btn);
}
void WindowsFight::retirerBouton(int index)
{
    vectorButton.erase(vectorButton.begin()+index);
}


