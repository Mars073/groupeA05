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


    this->texture = *tm->get("ui_bar");
    this->textureBorder = *tm->get("ui_bar-border");
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
    this->texture = other.texture;
    this->textureBorder = other.textureBorder;
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
    this->texture = other.texture;
    this->textureBorder = other.textureBorder;
    this->rect.setSize(sf::Vector2f(sizeX,sizeY));
    this->rect.setPosition(sf::Vector2f(posX,posY));
    this->rect.setFillColor(sf::Color(0,255,0));

    this->fond.setSize(sf::Vector2f(sizeX+1,sizeY+1));
    this->fond.setPosition(sf::Vector2f(posX,posY));
    this->fond.setOutlineThickness(5);
    this->fond.setOutlineColor(sf::Color(0,0,0));
    return *this;
}
void Bar::draw(RenderTarget& target, RenderStates states) const
{
    sf::Sprite sprites_b[3];
    for (sf::Sprite& s: sprites_b)
        s.setTexture(textureBorder);

    sprites_b[0].setTextureRect(sf::IntRect(0, 0, 12, 24));
    sprites_b[1].setTextureRect(sf::IntRect(12, 0, 1, 24));
    sprites_b[2].setTextureRect(sf::IntRect(13, 0, 12, 24));

    sprites_b[0].setPosition(posX-2, posY-2);
    sprites_b[1].setPosition(posX+10, posY-2);
    sprites_b[1].setScale(sizeX-20.f, 1.f);
    sprites_b[2].setPosition(posX+sizeX-10, posY-2);

    for (sf::Sprite& s: sprites_b)
        target.draw(s);


    sf::Sprite sprites[3];

    for (sf::Sprite& s: sprites)
    {
        s.setTexture(texture);
        s.setColor(rect.getFillColor());
    }

    int sizeX = rect.getSize().x;

    if (sizeX <= 20)
    {
        sprites[0].setTextureRect(sf::IntRect(0, 0, sizeX/2, 20));
        sprites[2].setTextureRect(sf::IntRect(11+sizeX/2, 0, sizeX/2, 20));
        sprites[0].setPosition(posX, posY);
        sprites[2].setPosition(posX+sizeX/2, posY);
        target.draw(sprites[0]);
        target.draw(sprites[2]);
        return;
    }

    sprites[0].setTextureRect(sf::IntRect(0, 0, 10, 20));
    sprites[1].setTextureRect(sf::IntRect(10, 0, 1, 20));
    sprites[2].setTextureRect(sf::IntRect(11, 0, 10, 20));

    if (sizeX <= 0)
        return;

    sprites[0].setPosition(posX, posY);
    sprites[1].setPosition(posX+10, posY);
    sprites[1].setScale(sizeX-20.f, 1.f);
    sprites[2].setPosition(posX+sizeX-10, posY);

    for (sf::Sprite& s: sprites)
        target.draw(s);
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
