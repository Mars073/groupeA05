#include "Weapon.h"


Weapon::Weapon(std::string itemName,std::string itemDescription,int atk,int mag):Item(itemName,itemDescription)
{
    itemType="Weapon";
    this->atk=atk;
    this->mag=mag;
}

Weapon::~Weapon()
{
    //dtor
}

Weapon::Weapon(const Weapon& w):Item(itemName,itemDescription)
{
    itemType="Weapon";
    this->atk=w.atk;
    this->mag=w.mag;
}

int Weapon::Getatk() const
{
    return atk;
}

void Weapon::Setatk(int val)
{
    atk = val;
}

int Weapon::Getmag() const
{
    return mag;
}

void Weapon::Setmag(int val)
{
    mag = val;
}

std::string Weapon::toString() const
{
    std::stringstream sstr;
    sstr<<Item::toString()<<std::endl<<"attack power : "<<Getatk()<<std::endl<<"magical power : "<<Getmag()<<std::endl;
    return sstr.str();
}
