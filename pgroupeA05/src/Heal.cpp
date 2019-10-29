#include "Heal.h"


Heal::Heal(std::string itemName,std::string itemDescription,int amountHealed):HealItem(itemName,itemDescription,amountHealed)
{
    itemType="Heal";
}

Heal::~Heal()
{

}

Heal::Heal(const Heal& h):HealItem(h)
{
    itemType="Heal";
}

Heal& Heal::operator=(const Heal& h){
    if(this!=&h){
        itemType="Heal";
    }
    return *this;
}

std::string Heal::str() const
{
    std::stringstream sstr;
    sstr<<HealItem::str()<<" hp"<<std::endl;
    return sstr.str();
}

std::string Heal::strEquipment() const
{
    std::stringstream sstr;
    sstr<<HealItem::strEquipment()<<" HP"<<std::endl;
    return sstr.str();
}

Heal* Heal::clone() const
{
    return new Heal(GetitemName(),GetitemDescription(),GetamountHealed());
}

