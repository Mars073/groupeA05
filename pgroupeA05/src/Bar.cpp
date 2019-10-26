#include "Bar.h"

Bar::Bar()
{
 //ctor
}
Bar::Bar(int posX, int posY, int sizeX, int sizeY)
{
 this->posX = posX;
 this->posY = posY;
 this->sizeX = sizeX;
 this->sizeX = sizeY;
 this->rect.setSize(sf::Vector2f(sizeX,sizeY));
 this->rect.setPosition(sf::Vector2f(posX,posY));
 this->rect.setFillColor(sf::Color(255,0,0));

 this->fond.setSize(sf::Vector2f(sizeX,sizeY));
 this->fond.setPosition(sf::Vector2f(posX,posY));
 this->fond.setOutlineThickness(5);
 this->fond.setOutlineColor(sf::Color(255,255,255));



}
Bar::~Bar()
{
 //dtor
}

Bar::Bar(const Bar& other)
{
 //copy ctor
}

Bar& Bar::operator=(const Bar& rhs)
{
 if (this == &rhs) return *this; // handle self assignment
 //assignment operator
 return *this;
}
sf::RectangleShape Bar::getRect()
{
 return rect;
}
sf::RectangleShape Bar::getFond()
{
 return fond;
}
void Bar::setBarLifeTaille(float current, float maxx)
{
 float pourcentage = (current/maxx);
 fond.setSize(sf::Vector2f(sizeX*pourcentage,sizeY));

}
