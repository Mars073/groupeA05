#include "View/Components/BtnDefend.h"

BtnDefend::BtnDefend(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
    //ctor
    this->setIsAttack(false);
    this->setVfxTexture("wind");
}
BtnDefend& BtnDefend::operator=(const BtnDefend& c)
 {
  this->BtnWin::operator=(c);
  this->setIsAttack(false);
  this->setVfxTexture("wind");
  return *this;
 }
//do an action when the button is activated
void BtnDefend::action()
{
    std::cout << "vous Defendez" << std::endl;

    std::cout <<getFm()->getMonster()->str()<< std::endl;
    std::cout <<getFm()->getPlayer()->str()<< std::endl;

}

BtnDefend::~BtnDefend()
{
    //dtor

}
BtnDefend::BtnDefend(BtnDefend const& btnA):BtnWin(btnA)
{
 this->setIsAttack(false);
 this->setVfxTexture("wind");
}
//return the decription
std::string BtnDefend::getDescription()
{

 std::string message;

 std::stringstream degatsStr;
 message ="you defend";

 degatsStr<<message;
 //degats =(getFm()->getMonster()->showDamageReceived(getFm()->getPlayer()->damageDone()));
 //degatsStr<<degats;




 return (degatsStr.str());
}
/** @brief clone
  *
  * clone the button
  */
BtnDefend* BtnDefend::clone()
{
  BtnDefend *btnMag = new BtnDefend(getPositionX(),getPositionY(),getTailleX(),getTailleY(),getTextButton());
  return btnMag;
}

    //dtor

    //this->text = c.text;



