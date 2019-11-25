#include "View/Components/WindowsFight.h"
#include "View/Components/BtnWin.h"
#include "iostream"
#include "View/Components/btnAttack.h"


//Constructor WindowsFight
WindowsFight::WindowsFight(int positionX,int positionY,int tailleX,int tailleY)
{
    this->rect.setPosition(sf::Vector2f(positionX,positionY));
    this->rect.setSize(sf::Vector2f(tailleX,tailleY));
    this->rect.setOutlineThickness(2);
    this->rect.setOutlineColor(sf::Color(255,255,255));
    this->rect.setFillColor(sf::Color(0,0,255));
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
//Destructor WindowsFoght
WindowsFight::~WindowsFight()
{
    for(int i = 0; i< this->vectorButton.size();i++)
    {
        std::cout <<i <<"bouton supprimer"<<std::endl;
        BtnWin *mp =(this->vectorButton.at(i));
        delete mp;
    }
    this->vectorButton.clear();


}
//getter PositionX
int WindowsFight::getPositionX() const
{
    return positionX;
}
//getter PositionY
int WindowsFight::getPositionY()const
{
    return positionY;
}
//Getter tailleX
int WindowsFight::getTailleX()const
{
    return tailleX;
}
//Getter tailleY
int WindowsFight::getTailleY()const
{
    return tailleY;
}
//Getter Rect
sf::RectangleShape WindowsFight::getRect()const
{
    return rect;
}
//getteur Draw
void WindowsFight::draw(sf::RenderWindow &rd)
{
    rd.draw(rect);

}
//getter of vector Button
std::vector<BtnWin*> WindowsFight::getVect()const
{
    return vectorButton;
}
//check activate
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
    for(int i = 0;i < vectorButton.size();i++)
    {
        vectorButton.at(i)->changeColorDesactivate();
        vectorButton.at(i)->Desativate();
    }
    vectorButton.at(index)->changeColorActivate();
    vectorButton.at(index)->ativate();
}
//return number of button
int WindowsFight::getNbBoutton()
{
    return (vectorButton.size()-1);
}
//add button in vector
void WindowsFight::addButton(BtnWin *btn)
{
    vectorButton.push_back(btn);
}
//remove a button
void WindowsFight::removeButton(int index)
{
    vectorButton.erase(vectorButton.begin()+index);
}
//setter of fightManager
void WindowsFight::setFm(FightManager *newfm)
{
    fm = newfm;
}
//clear and delete the vector of ClearWindows
void WindowsFight::ClearWindows()
{
 for(int i ;i<this->vectorButton.size();i++)
 {
  delete vectorButton.at(i);
 }
 this->vectorButton.clear();
}
WindowsFight& WindowsFight::operator=(const WindowsFight& rhs)
{
    if (this == &rhs)
        return *this; // handle self assignment
//assignment operator
    return *this;
}
/** @brief WindowsFight
  *
  * copy constuctor
  */
WindowsFight::WindowsFight(const WindowsFight& other)
{
   this->rect.setPosition(sf::Vector2f(other.getPositionX(),other.getPositionY()));
    this->rect.setSize(sf::Vector2f(other.getTailleX(),other.getTailleY()));
    this->rect.setOutlineThickness(2);
    this->rect.setOutlineColor(sf::Color(255,255,255));
    this->rect.setFillColor(sf::Color(0,0,255));
    this->indexSelectionner = 0;

    //initialisation cf attribut
    this->positionX = other.getPositionX();
    this->positionY = other.getPositionY();
    this->tailleX = other.getTailleX();
    this->tailleY = other.getTailleY();
}






