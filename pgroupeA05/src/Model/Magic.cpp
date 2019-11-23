#include "Magic.h"

Magic::Magic(std::string mName,int baseDamage,int mpUsage)
{
    this->mName=mName;
    this->baseDamage=baseDamage;
    this->mpUsage=mpUsage;
}

Magic::~Magic()
{
    //dtor
}

Magic::Magic(const Magic& m)
{
    this->mName=m.mName;
    this->baseDamage=m.baseDamage;
    this->mpUsage=m.mpUsage;
}

Magic& Magic::operator=(const Magic& m)
{
    if (this != &m){
        this->mName=m.mName;
        this->baseDamage=m.baseDamage;
        this->mpUsage=m.mpUsage;
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

int Magic::GetmpUsage()const
{
    return mpUsage;
}

void Magic::SetmpUsage(int val)
{
    mpUsage = val;
}

std::string Magic::str() const
{
    std::stringstream sstr;
    sstr<<"Name : "<<GetmName()<<std::endl;
    return sstr.str();
}

Magic* Magic::clone() const
{
    return new Magic(GetmName(),GetbaseDamage(),GetmpUsage());
}

bool Magic::operator==(const Magic& other) const
{
    return mName == other.GetmName();
}
