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
  if(!this->getIsMenuBoutton())
  {
   delete magic;
  }
  int n = this->getListButton().size();
   for(int i = 0;i<n;i++)
   {
    delete(this->getListButton().at(i));
    std::cout <<i<<"supprimer" <<endl;
   }
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
   btnMagCreate->Setmagic(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i)->clone());
   btnMagCreate->setNomText(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i)->GetmName());
   btnMagCreate->setFm(this->getFm());

   this->AddButton(btnMagCreate);
   //delete btnMagCreate;

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

 std::string message;
 int degats;
 std::stringstream degatsStr;
 message ="you cast a spell which make ";

 degatsStr<<message;
 degats =magic->GetbaseDamage();
 degatsStr<<degats;

 std::cout <<degatsStr.str()<<std::endl;


// return degatsStr.str();
   return degatsStr.str();
}
BtnMagic* BtnMagic::Clone()
 {
  BtnMagic *btnMag = new BtnMagic(getPositionX(),getPositionY(),getTailleX(),getTailleY(),getTextButton());
  if(this->getIsMenuBoutton())
  {
    btnMag->setIsMenuBoutton(true);
  }
  return btnMag;
 }
