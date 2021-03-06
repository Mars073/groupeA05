#include "View/Components/BtnMagic.h"
//constructeur
BtnMagic::BtnMagic(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{

 //ctor
 this->setIsAttack(true);

}
//destructor
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




//copy constructor
BtnMagic::BtnMagic(const BtnMagic& other):BtnWin(other)
{
 //copy ctor
}
//redifining operator =
BtnMagic& BtnMagic::operator=(const BtnMagic& rhs)
{
 if (this == &rhs) return *this; // handle self assignment
 //assignment operator
 BtnWin::operator=(rhs);
 return *this;
}
//do an action when the button is activated
void BtnMagic::action()
{
 //if this button is a menuButton
 int t = 0;
 if(this->getIsMenuBoutton())
 {
  for(size_t i = 0 ;i<this->getFm()->getPlayer()->Getspells()->GetspellsHeld().size();i++)
  {
   std::cout <<this->getNbBoutonDisplay()<<"le nombre maximum de btnAfficher" << std::endl;
   if(t >=this->getNbBoutonDisplay())
   {
    t=0;
   }
   BtnMagic *btnMagCreate = new BtnMagic(this->getPositionX()+325,257+(50*t),70,35,"p");
   btnMagCreate->Setmagic(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i)->clone());
   btnMagCreate->setNomText(this->getFm()->getPlayer()->Getspells()->GetspellsHeld().at(i)->GetmName());
   btnMagCreate->setFm(this->getFm());
   std::cout<<btnMagCreate->Getmagic()->GetmName() <<std::endl;
   btnMagCreate->setVfxTexture(btnMagCreate->Getmagic()->GetmName());

   this->AddButton(btnMagCreate);
   //delete btnMagCreate;
   t++;

  }
 }
 else
 {
     std::cout<<"magie util"<< std::endl;
     this->getFm()->DamageMagicPlayer(magic);
     this->getFm()->DamageMonster();
 }

}
//return description
std::string BtnMagic::getDescription()const
{

 std::string message;
 int degats;
 std::stringstream degatsStr;
 message =" you cast a spell which try to make ";

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
