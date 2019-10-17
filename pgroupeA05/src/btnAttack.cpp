#include "btnAttack.h"

btnAttack::btnAttack(int positionX,int positionY,int tailleX,int tailleY,std::string textButton):BtnWin(positionX,positionY,tailleX,tailleY,textButton)
{
    //ctor
}
void btnAttack::action()
{
    std::cout << "vous attaquez" << std::endl;
}

btnAttack::~btnAttack()
{
    //dtor

}
btnAttack::btnAttack(btnAttack const& btnA)
{
    //dtor
    this->setPositionX(btnA.getPositionX());
    this->setPositionY(btnA.getPositionY());
    this->setTailleX(btnA.getTailleX());
    this->setTailleY(btnA.getTailleY());

}
