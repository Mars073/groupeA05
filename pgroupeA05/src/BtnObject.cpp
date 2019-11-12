#include "BtnObject.h"

BtnObject::BtnObject(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
 //ctor
}

BtnObject::~BtnObject()
{
 //dtor
}

BtnObject::BtnObject(const BtnObject& other):BtnWin(other)
{
 //copy ctor
}
void BtnObject::setItem(Item* Item)
{
 item = Item;
}

BtnObject& BtnObject::operator=(const BtnObject& rhs)
{
 if (this == &rhs) return *this; // handle self assignment
 //assignment operator
 return *this;
}
void BtnObject::action()
{
 //if this button is a menuButton

 if(this->getIsMenuBoutton())
 {
    for(int i = 0 ;i<this->getFm()->getPlayer()->Getinventory()->Getbag().size();i++)
    {
      if(this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->GetitemType()=="Heal" || this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->GetitemType()=="HealMp"){
           BtnObject *btnObjCreate = new BtnObject(this->getPositionX()+325,250+(50*i),70,35,"p");
           btnObjCreate->setItem(this->getFm()->getPlayer()->Getinventory()->Getbag().at(i));
           btnObjCreate->setNomText(this->getFm()->getPlayer()->Getinventory()->Getbag().at(i)->GetitemName());
           btnObjCreate->setFm(this->getFm());
           this->AddButton(btnObjCreate);
      }
    }
 }
 else
 {
     std::cout<<"Object util"<< std::endl;


 }

}
std::string BtnObject::getDescription()
{
 std::string message;
 int degats;
 std::stringstream degatsStr;
 message ="vous avez fait utiliser ";

 degatsStr<<message;
 degatsStr<<item->GetitemName();


 std::cout <<degatsStr.str()<<std::endl;

 return degatsStr.str();
}

