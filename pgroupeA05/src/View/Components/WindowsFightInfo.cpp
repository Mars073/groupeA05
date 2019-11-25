#include "View/Components/WindowsFightInfo.h"

WindowsFightInfo::WindowsFightInfo(int posX,int posY,int sizeX,int sizeY):WindowsFight(posX,posY,sizeX,sizeY)
{
    //ctor
    /*
    this->getVect().clear();
    for(int i = 0;i<this->getNbBoutton();i++)
    {
        delete(this->getVect().at(i));
    }
    */



}

WindowsFightInfo::~WindowsFightInfo()
{
    //dtor
    this->~WindowsFight();
}
/** @brief operator=
  *
  * assignment operator
  */
WindowsFightInfo& WindowsFightInfo::operator=(const WindowsFightInfo& rhs)
{
   if (this == &rhs)
        return *this; // handle self assignment
//assignment operator
    return *this;

}

/** @brief WindowsFightInfo
  *
  * copy constructor
  */
WindowsFightInfo::WindowsFightInfo(const WindowsFightInfo& other):WindowsFight(other)
{

}

void WindowsFightInfo::EcrireinWindow()
{

}
