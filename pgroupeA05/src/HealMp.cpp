#include "HealMp.h"

HealMp::HealMp(std::string itemName,std::string itemDescription,int amountHealed):HealItem(itemName,itemDescription,amountHealed)
{
    SetitemType("HealMp");
}

HealMp::~HealMp()
{
    //dtor
}

HealMp::HealMp(const HealMp& h):HealItem(h)
{
    SetitemType(h.GetitemType());
}

HealMp& HealMp::operator=(const HealMp& h){
    if(this!=&h){
        Item::operator=(h);
        SetitemType(h.GetitemType());
    }
    return *this;
}

std::string HealMp::str() const
{
    std::stringstream sstr;
    sstr<<HealItem::str()<<" mp"<<std::endl;
    return sstr.str();
}

std::string HealMp::strEquipment() const
{
    std::stringstream sstr;
    sstr<<HealItem::strEquipment()<<" MP"<<std::endl;
    return sstr.str();
}

HealMp* HealMp::clone() const
{
    return new HealMp(GetitemName(),GetitemDescription(),GetamountHealed());
}
