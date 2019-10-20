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
btnAttack::btnAttack(btnAttack const& btnA):BtnWin(btnA)
{

}

    //dtor

    //this->text = c.text;



