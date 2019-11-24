#include "View/Components/btnAttack.h"
//Constructor
btnAttack::btnAttack(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
    //ctor
    this->setVfxTexture();
    this->setIsAttack(true);
}
//Make a action when button is activate
void btnAttack::action()
{
    std::cout << "vous attaquez" << std::endl;
    getFm()->DamagePlayer();
    std::cout <<getFm()->getMonster()->str()<< std::endl;
    std::cout <<getFm()->getPlayer()->str()<< std::endl;

}

btnAttack::~btnAttack()
{
    //dtor

}
btnAttack::btnAttack(btnAttack const& btnA):BtnWin(btnA)
{
  this->setVfxTexture();
  this->setIsAttack(true);
}
//enable to return description
std::string btnAttack::getDescription()
{

 std::string message;
 int degats;
 std::stringstream degatsStr;
 message ="you are doing an attack ";

 degatsStr<<message;
 degats =(getFm()->getMonster()->showDamageReceived(getFm()->getPlayer()->damageDone()));
 degatsStr<<degats;

 std::cout<<"les degats "<<degats<<std::endl;

 return (degatsStr.str());
}
/** @brief clone
  *
  * @todo: document this function
  */
btnAttack* btnAttack::clone()
{
  btnAttack *btnMag = new btnAttack(getPositionX(),getPositionY(),getTailleX(),getTailleY(),getTextButton());
  return btnMag;
}

    //dtor

    //this->text = c.text;


