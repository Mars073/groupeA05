#include "BtnWin.h"


BtnWin::BtnWin(int positionX,int positionY,int tailleX,int tailleY,std::string textButton)
{
    this->rect.setPosition(sf::Vector2f(positionX,positionY));
    this->rect.setSize(sf::Vector2f(tailleX,tailleY));
    this->rect.setOutlineThickness(5);
    this->rect.setOutlineColor(sf::Color(0,0,255));





    sf::Text text;
    //this->text.setFont(ft); // font est un sf::Font
    // choix de la cha�ne de caract�res � afficher
    this->text.setString(textButton);
    this->text.setCharacterSize(15); // exprim�e en pixels, pas en points !
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->text.setPosition(positionX,positionY);
    this->text.setFillColor(sf::Color(0,0,255));
    this->strat = strat;

    /*
    this->txt.setFont(this->font);
    this->txt.setPosition(sf::Vector2f(positionX,positionY));


    this->txt.setString("papapapapa");
    this->txt.setFillColor(sf::Color(255,255,255));
    this->txt.setColor(sf::Color(255,0,0));
    this->txt.setCharacterSize(10);
    this->txt.setPosition(sf::Vector2f(100,100));
    this->txt.setOutlineThickness(4);
    */

    // Design paterne strategie car le masquage des methode ne marche pas dans les vector


}
void BtnWin::ativate()
{
 isActivate = true;
}
void BtnWin::Desativate()
{
 isActivate = false;
}
int BtnWin::getPositionX() const
{
    return positionX;
}
int BtnWin::getPositionY()const
{
    return positionY;
}
int BtnWin::getTailleX()const
{
    return tailleX;
}
int BtnWin::getTailleY()const
{
    return tailleY;
}
sf::RectangleShape BtnWin::getRect()const
{
    return rect;
}
void BtnWin::changeColorActivate()
{
    rect.setOutlineColor(sf::Color(255,0,0));
}
void BtnWin::changeColorDesactivate()
{
    rect.setOutlineColor(sf::Color(0,0,0));
}

sf::Text BtnWin::getText()
{
    return text;
}
void BtnWin::action()
{
    std::cout << "vous avez fait une action"<< std::endl;
}
bool BtnWin::getisActivate()
{
    return isActivate;
}
void BtnWin::setIsActivate(bool val)
{
    isActivate = val;
}

BtnWin::~BtnWin()
{
    //dtor
}
