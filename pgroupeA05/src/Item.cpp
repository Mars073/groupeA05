#include "Item.h"


Item::Item(std::string itemName,std::string itemDescription)
{
    this->itemName=itemName;
    this->itemDescription=itemDescription;

}

Item::~Item()
{

}

Item::Item(const Item& i)
{
    this->itemName=i.itemName;
    this->itemDescription=i.itemDescription;

}

Item& Item::operator=(const Item& i){
    if(this!=&i){
        this->itemName=i.itemName;
        this->itemDescription=i.itemDescription;
    }
    return *this;
}

std::string Item::GetitemName() const
{
    return itemName;
}

void Item::SetitemName(std::string val)
{
    itemName = val;
}

std::string Item::GetitemDescription() const
{
    return itemDescription;
}

void Item::SetitemDescription(std::string val)
{
    itemDescription = val;
}

std::string Item::GetitemType() const
{
    return itemType;
}

void Item::SetitemType(std::string val)
{
    itemType = val;
}

std::string Item::str() const
{
    std::stringstream sstr;
    sstr<<"name : " <<GetitemName()<<std::endl<<"description : "<<GetitemDescription()<<std::endl<<GetitemType();
    return sstr.str();
}

Item* Item::clone() const
{
    return new Item(GetitemName(),GetitemDescription());
}

bool Item::operator==(const Item& other) const
{
    return itemName == other.GetitemName() && itemDescription == other.GetitemDescription() && itemType == other.GetitemType();
}
