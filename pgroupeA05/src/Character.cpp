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

Character& Character::operator=(const Character& c){
    if(this!=&c){
        this->charaName=c.charaName;
    }
    return *this;
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

std::string Character::str() const
{
    std::stringstream sstr;
    sstr<<GetcharaName();
    return sstr.str();
}

Character* Character::clone() const
{
    return new Character(GetcharaName());
}
