#include "DrawableMonster.h"

DrawableMonster::DrawableMonster(string Snom):nom(Snom)
{
 ms = bs.getOneMonster(nom);
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
 text = textureManager->get(("data/images/monsters/"+nom));
}
void DrawableMonster::SetSprite(sf::Texture val)
{
 sprite.setTexture(val);
}


