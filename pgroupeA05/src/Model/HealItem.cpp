#include "Model/HealItem.h"

HealItem::HealItem(std::string itemName,std::string itemDescription,int amountHealed):Item(itemName,itemDescription)
{
    this->amountHealed=amountHealed;
}

HealItem::~HealItem()
{
    //dtor
}

HealItem::HealItem(const HealItem& h):Item(h)
{
    this->amountHealed=h.amountHealed;
}

HealItem& HealItem::operator=(const HealItem& h)
{
    if(this!=&h){
        Item::operator=(h);
        this->amountHealed=h.amountHealed;
    }
    return *this;
}

int HealItem::GetamountHealed() const
{
    return amountHealed;
}

void HealItem::SetamountHealed(int val)
{
    amountHealed = val;
}

std::string HealItem::str() const
{
    std::stringstream sstr;
    sstr<<Item::str()<<std::endl<<"Amount healed : "<<GetamountHealed();
    return sstr.str();
}

std::string HealItem::strEquipment() const
{
    std::stringstream sstr;
    sstr<<Item::strEquipment()<<" "<<GetamountHealed();
    return sstr.str();
}

HealItem* HealItem::clone() const
{
    return new HealItem(GetitemName(),GetitemDescription(),GetamountHealed());
}
