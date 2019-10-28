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

Weapon::Weapon(const Weapon& w):Item(w)
{
    itemType="Weapon";
    this->atk=w.atk;
    this->mag=w.mag;
}

Weapon& Weapon::operator=(const Weapon& w){
    if(this!=&w){
        itemType="Weapon";
        this->atk=w.atk;
        this->mag=w.mag;
    }
    return *this;
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

std::string Weapon::str() const
{
    std::stringstream sstr;
    sstr<<Item::str()<<std::endl<<"attack power : "<<Getatk()<<std::endl<<"magical power : "<<Getmag()<<std::endl;
    return sstr.str();
}

std::string Weapon::strEquipment() const
{
    std::stringstream sstr;
    sstr<<Item::strEquipment()<<" ATK : "<<Getatk()<<" MAG : "<<Getmag()<<std::endl;
    return sstr.str();
}

Weapon* Weapon::clone() const
{
    return new Weapon(GetitemName(),GetitemDescription(),Getatk(),Getmag());
}
