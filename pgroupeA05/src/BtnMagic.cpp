#include "BtnMagic.h"

BtnMagic::BtnMagic(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
 //ctor

 this->setNomText(textButton);
}

BtnMagic::~BtnMagic()
{
 //dtor
}

BtnMagic::BtnMagic(const BtnMagic& other):BtnWin(other)
{
 //copy ctor
}

BtnMagic& BtnMagic::operator=(const BtnMagic& rhs)
{
 if (this == &rhs) return *this; // handle self assignment
 //assignment operator
 return *this;
}
