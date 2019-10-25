#include "btnAttack.h"

btnAttack::btnAttack(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
    //ctor
}
void btnAttack::action(Player *pl,Monster *ms)
{
    std::cout << "vous attaquez" << std::endl;
    getFm()->DamageMonster();

}

btnAttack::~btnAttack()
{
    //dtor

}
btnAttack::btnAttack(btnAttack const& btnA):BtnWin(btnA)
{

}

    //dtor

    //this->text = c.text;



