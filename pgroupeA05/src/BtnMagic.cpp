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
   BtnMagic *btnMagCreate = new BtnMagic(this->getPositionX()+325,257+(50*i),70,35,"p");
   btnMagCreate->Setmagic(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i));
   btnMagCreate->setNomText(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i)->GetmName());
   btnMagCreate->setFm(this->getFm());
   this->AddButton(btnMagCreate);

  }
 }
 else
 {
     std::cout<<"magie util"<< std::endl;
     this->getFm()->DamageMagicPlayer(magic);
     this->getFm()->DamageMonster();
 }

}
std::string BtnMagic::getDescription()
{
 return ("vous avez fait "+getFm()->getPlayer()->Getatk());
}
