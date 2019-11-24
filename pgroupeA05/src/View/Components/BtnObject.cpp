#include "View/Components/BtnObject.h"

BtnObject::BtnObject(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
 //ctor
 this->setIsAttack(false);
}

BtnObject::~BtnObject()
{
 //dtor
  if(!this->getIsMenuBoutton())
  {
   delete item;
  }
  int n = this->getListButton().size();
  for(int i = 0;i<n;i++)
  {
    delete(this->getListButton().at(i));
  }

}

BtnObject::BtnObject(const BtnObject& other):BtnWin(other)
{
 //copy ctor
}
void BtnObject::setItem(Item* Item)
{
 item = Item->clone();
}

BtnObject& BtnObject::operator=(const BtnObject& rhs)
{
 if (this == &rhs) return *this; // handle self assignment
 //assignment operator
 return *this;
}
//do an action when the button is activated
void BtnObject::action()
{
 //if this button is a menuButton
 int t = 0;
 if(this->getIsMenuBoutton())
 {
    for(int i = 0 ;i<this->getFm()->getPlayer()->Getinventory()->Getbag().size();i++)
    {
      std::cout <<this->getNbBoutonDisplay()<<"le nombre maximum de btnAfficher" << std::endl;
      if(t >=this->getNbBoutonDisplay())
      {
       t=0;
      }
      if(this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->GetitemType()=="Heal" || this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->GetitemType()=="HealMp"){
           std::cout <<"objet creer"<<std::endl;
            BtnObject *btnObjCreate = new BtnObject(this->getPositionX()+325,250+(50*t),70,35,"p");
           btnObjCreate->setItem(this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->clone());
           btnObjCreate->setNomText(this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->GetitemName());
           btnObjCreate->setFm(this->getFm());
           btnObjCreate->setVfxTexture("wind");
           this->AddButton(btnObjCreate);
           t++;
      }
    }
 }
 else
 {
     std::cout<<"Object utiliser"<< std::endl;
     getFm()->getPlayer()->heals(item);
 }

}
std::string BtnObject::getDescription()
{
 std::string message;
 int degats;
 std::stringstream degatsStr;
 message ="you use a";

 degatsStr<<message;
 degatsStr<<item->GetitemName();


 std::cout <<degatsStr.str()<<std::endl;

 return degatsStr.str();
}
/** @brief clone
  *
  * @todo: document this function
  */
BtnObject* BtnObject::clone()
{
  BtnObject *btnMag = new BtnObject(getPositionX(),getPositionY(),getTailleX(),getTailleY(),getTextButton());
  if(this->getIsMenuBoutton())
  {
    btnMag->setIsMenuBoutton(true);
  }
  return btnMag;
}



