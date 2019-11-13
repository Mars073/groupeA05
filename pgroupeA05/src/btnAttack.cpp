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
 message ="you are doing an attack ";

 degatsStr<<message;
 degats =(getFm()->getMonster()->showDamageReceived(getFm()->getPlayer()->damageDone()));
 degatsStr<<degats;

 std::cout<<"les degats "<<degats<<std::endl;

 return (degatsStr.str());
}

    //dtor

    //this->text = c.text;



