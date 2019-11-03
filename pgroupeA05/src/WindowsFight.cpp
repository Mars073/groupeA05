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

    //initialisation cf attribut
    this->positionX = positionX;
    this->positionY = positionY;
    this->tailleX = tailleX;
    this->tailleY = tailleY;




    /*
    btnAttack *btnObjet = new btnAttack(positionX,positionY+100,80,50,"Objet");


    this->vectorButton.push_back(btn);
    this->vectorButton.push_back(btnMagie);C:\wamp64\www\EntrainementTm\groupeA05
    this->vectorButton.push_back(btnObjet);
    */
    //this->vectorButton.push_back(new btnAttack(*(btnMagie)));

}

WindowsFight::~WindowsFight()
{
    for(int i = 0; i< this->vectorButton.size()-1;i++)
    {
        delete(this->vectorButton.at(i));
    }

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
std::vector<BtnWin*> WindowsFight::getVect()const
{
    return vectorButton;
}
void WindowsFight::activateButton(int index)
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
void WindowsFight::addButton(BtnWin *btn)
{
    vectorButton.push_back(btn);
}
void WindowsFight::retirerBouton(int index)
{
    vectorButton.erase(vectorButton.begin()+index);
}
void WindowsFight::setFm(FightManager *newfm)
{
    fm = newfm;
}
void WindowsFight::ClearWindows()
{
 this->vectorButton.clear();
}



