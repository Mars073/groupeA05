#include "Inventory.h"


Inventory::Inventory()
{


}

Inventory::~Inventory()
{

}

Inventory::Inventory(const Inventory& i)
{


}

void Inventory::addItem(Item *item)
{
    bag.push_back(item);
}

std::list<Item*> Inventory::Getbag() const
{
    return bag;
}

std::string Inventory::str() const
{
    std::stringstream sstr;
    //std::list<Item>::iterator it;
    sstr<<"Items : " <<std::endl<<std::endl;
    for (auto const& i : bag){
        //sstr<<it->str()<<endl;
        sstr<<i->str()<<std::endl;
    }

    return sstr.str();
}
