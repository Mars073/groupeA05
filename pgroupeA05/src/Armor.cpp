#include "Armor.h"

Armor::Armor(std::string itemName,std::string itemDescription,int def):Item(itemName,itemDescription)
{
    itemType="Armor";
    this->def=def;
}

Armor::~Armor()
{
    //dtor
}

Armor::Armor(const Armor& a):Item(itemName,itemDescription)
{
    itemType="Armor";
    this->def=a.def;
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
