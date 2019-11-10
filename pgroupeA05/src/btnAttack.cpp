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
 return ("vous avez fait "+getFm()->getPlayer()->Getatk());
}

    //dtor

    //this->text = c.text;



