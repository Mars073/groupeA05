#include "Magic.h"

Magic::Magic(std::string mName,int baseDamage)
{
    this->mName=mName;
    this->baseDamage=baseDamage;
}

Magic::~Magic()
{
    //dtor
}

Magic::Magic(const Magic& m)
{
    this->mName=m.mName;
    this->baseDamage=m.baseDamage;
}

Magic& Magic::operator=(const Magic& m)
{
    if (this != &m){
        this->mName=m.mName;
        this->baseDamage=m.baseDamage;
    }
    return *this;
}

std::string Magic::GetmName()const
{
    return mName;
}

void Magic::SetmName(std::string val)
{
    mName = val;
}

int Magic::GetbaseDamage()const
{
    return baseDamage;
}

void Magic::SetbaseDamage(int val)
{
    baseDamage = val;
}

std::string Magic::str() const
{
    std::stringstream sstr;
    sstr<<"Name : "<<GetmName()<<std::endl;
    return sstr.str();
}
