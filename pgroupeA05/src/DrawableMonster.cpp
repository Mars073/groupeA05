#include "DrawableMonster.h"

DrawableMonster::DrawableMonster(std::string &Snom):nom(Snom)
{





}
DrawableMonster::DrawableMonster()
{
 this->textureManager = TexturesManager::getInstance();
}

DrawableMonster::~DrawableMonster()
{
 //dtor
 delete(ms);
 delete(textureManager);
}

DrawableMonster::DrawableMonster(const DrawableMonster& other)
{
 //copy ctor
}

DrawableMonster& DrawableMonster::operator=(const DrawableMonster& rhs)
{
 if (this == &rhs) return *this; // handle self assignment
 //assignment operator
 return *this;
}
void DrawableMonster::SetTexture(string nom)
{

 text = Resources::getTexture("boss","data/images/monsters/boss.png");
 this->SetSprite(text);
 ms =bs.getOneMonster(nom);
}
void DrawableMonster::SetSprite(sf::Texture val)
{
 sprite.setTexture(val);
}


