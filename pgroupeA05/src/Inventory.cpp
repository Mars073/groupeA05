#include "Inventory.h"


Inventory::Inventory()
{


}

Inventory::~Inventory()
{
    for (auto const& i : bag){
        delete i;
    }
}

Inventory::Inventory(const Inventory& i)
{


}

Inventory& Inventory::operator=(const Inventory& i){
    if(this!=&i){
        for (auto const& i : bag){
            delete i;
        }
    }
    return *this;
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
