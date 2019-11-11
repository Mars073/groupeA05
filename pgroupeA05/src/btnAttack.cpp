#include "btnAttack.h"

btnAttack::btnAttack(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
    //ctor
}
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

}
std::string btnAttack::getDescription()
{
 std::string message;
 int degats;
 std::stringstream degatsStr;
 message ="vous avez fait ";

 degatsStr<<message;
 degats =getFm()->getPlayer()->damageDone();
 degatsStr<<degats;

 std::cout <<degatsStr.str()<<std::endl;

 return (message);
}

    //dtor

    //this->text = c.text;



