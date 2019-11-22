#include "BtnDefend.h"

BtnDefend::BtnDefend(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
    //ctor
}
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

}
std::string BtnDefend::getDescription()
{

 std::string message;
 int degats;
 std::stringstream degatsStr;
 message ="you defend";

 degatsStr<<message;
 //degats =(getFm()->getMonster()->showDamageReceived(getFm()->getPlayer()->damageDone()));
 //degatsStr<<degats;




 return (degatsStr.str());
}
/** @brief clone
  *
  * @todo: document this function
  */
BtnDefend* BtnDefend::clone()
{
  BtnDefend *btnMag = new BtnDefend(getPositionX(),getPositionY(),getTailleX(),getTailleY(),getTextButton());
  return btnMag;
}

    //dtor

    //this->text = c.text;



