#include "View/Components/Bar.h"

Bar::Bar()
{
//ctor
}
Bar::Bar(int posX, int posY, int sizeX, int sizeY)
{
    this->posX = posX;
    this->posY = posY;
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->rect.setSize(sf::Vector2f(sizeX,sizeY));
    this->rect.setPosition(sf::Vector2f(posX,posY));
    this->rect.setFillColor(sf::Color(0,255,0));

    this->fond.setSize(sf::Vector2f(sizeX,sizeY));
    this->fond.setPosition(sf::Vector2f(posX,posY));
    this->fond.setOutlineThickness(5);
    this->fond.setOutlineColor(sf::Color(0,0,0));



}
Bar::~Bar()
{
//dtor

}

Bar::Bar(const Bar& other)
{
//copy ctor
    this->posX = other.posX;
    this->posY = other.posY;
    this->sizeX = other.sizeX;
    this->sizeY = other.sizeY;
    this->rect.setSize(sf::Vector2f(sizeX,sizeY));
    this->rect.setPosition(sf::Vector2f(posX,posY));
    this->rect.setFillColor(sf::Color(0,255,0));

    this->fond.setSize(sf::Vector2f(sizeX,sizeY));
    this->fond.setPosition(sf::Vector2f(posX,posY));
    this->fond.setOutlineThickness(5);
    this->fond.setOutlineColor(sf::Color(0,0,0));
}

Bar& Bar::operator=(const Bar& other)
{
    if (this == &other)
        return *this; // handle self assignment
//assignment operator
    this->posX = other.posX;
    this->posY = other.posY;
    this->sizeX = other.sizeX;
    this->sizeY = other.sizeY;
    this->rect.setSize(sf::Vector2f(sizeX,sizeY));
    this->rect.setPosition(sf::Vector2f(posX,posY));
    this->rect.setFillColor(sf::Color(0,255,0));

    this->fond.setSize(sf::Vector2f(sizeX+1,sizeY+1));
    this->fond.setPosition(sf::Vector2f(posX,posY));
    this->fond.setOutlineThickness(5);
    this->fond.setOutlineColor(sf::Color(0,0,0));
    return *this;
}
sf::RectangleShape Bar::getRect()const
{
    return rect;
}
sf::RectangleShape Bar::getFond()const
{
    return fond;
}
void Bar::setBarLifeTaille(float current, float maxx)
{
    float pourcentage = (current/maxx);

    if(pourcentage <0)
    {
        pourcentage = 0;
    }

    this->rect.setSize(sf::Vector2f(((this->sizeX)*pourcentage),(this->sizeY)));

}
void Bar::Setcolor(sf::Color val)
{
    rect.setFillColor(val);
}
