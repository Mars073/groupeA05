#include "Model/Armor.h"

Armor::Armor(std::string itemName,std::string itemDescription,int def):Item(itemName,itemDescription)
{
    SetitemType("Armor");
    this->def=def;
}

Armor::~Armor()
{
    //dtor
}

Armor::Armor(const Armor& a):Item(a)
{
    SetitemType(a.GetitemType());
    this->def=a.def;
}

Armor& Armor::operator=(const Armor& a){
    if(this!=&a){
        Item::operator=(a);
        SetitemType(a.GetitemType());
        this->def=a.def;
    }
    return *this;
}

int Armor::Getdef() const
{
    return def;
}

void Armor::Setdef(int val)
{
    def = val;
}

std::string Armor::str() const
{
    std::stringstream sstr;
    sstr<<Item::str()<<std::endl<<"defense : "<<Getdef()<<std::endl;
    return sstr.str();
}

std::string Armor::strEquipment() const
{
    std::stringstream sstr;
    sstr<<Item::strEquipment()<<" DEF : "<<Getdef()<<std::endl;
    return sstr.str();
}

Armor* Armor::clone() const
{
    return new Armor(GetitemName(),GetitemDescription(),Getdef());
}
