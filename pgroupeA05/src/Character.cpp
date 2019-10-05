#include "Character.h"

Character::Character(std::string charaName)
{
    this->charaName=charaName;

}
Character::~Character()
{
    //dtor
}

Character::Character(const Character& c)
{
    this->charaName=c.charaName;

}

std::string Character::GetcharaName() const
{
    return charaName;
}

void Character::SetcharaName(std::string val)
{
    charaName = val;
}

std::string Character::GetcharaType() const
{
    return charaType;
}

void Character::SetcharaType(std::string val)
{
    charaType = val;
}

std::string Character::toString() const
{
    std::stringstream sstr;
    sstr<<"name : "<<GetcharaName()<<std::endl<<GetcharaType();
    return sstr.str();
}
