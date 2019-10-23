#include "Heal.h"


Heal::Heal(std::string itemName,std::string itemDescription,int amountHealed):Item(itemName,itemDescription)
{
    itemType="Heal";
    this->amountHealed=amountHealed;
}

Heal::~Heal()
{

}

Heal::Heal(const Heal& h):Item(h)
{
    itemType="Heal";
    this->amountHealed=h.amountHealed;
}

Heal& Heal::operator=(const Heal& h){
    if(this!=&h){
        itemType="Heal";
        this->amountHealed=h.amountHealed;
    }
    return *this;
}

int Heal::GetamountHealed() const
{
    return amountHealed;
}

void Heal::SetamountHealed(int val)
{
    amountHealed = val;
}

std::string Heal::str() const
{
    std::stringstream sstr;
    sstr<<Item::str()<<std::endl<<"Amount healed : "<<GetamountHealed()<<" hp"<<std::endl;
    return sstr.str();
}
