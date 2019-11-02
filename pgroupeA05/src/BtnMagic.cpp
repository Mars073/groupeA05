#include "BtnMagic.h"

BtnMagic::BtnMagic(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
 //ctor

 //this->setNomText(textButton);
 std::cout <<"coucou" <<std::endl;
}

BtnMagic::~BtnMagic()
{
 //dtor
 delete(magic);
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
void BtnMagic::action()
{
 //if this button is a menuButton

 if(this->getIsMenuBoutton())
 {
  for(int i = 0 ;i<this->getFm()->getPlayer()->Getspells()->GetspellsHeld().size();i++)
  {
   BtnMagic *btnMagCreate = new BtnMagic(this->getPositionX()+220,200+(50*i),80,50,"p");
   btnMagCreate->Setmagic(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i));
   btnMagCreate->setNomText(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i)->GetmName());
   this->AddButton(btnMagCreate);

  }

 }

}
