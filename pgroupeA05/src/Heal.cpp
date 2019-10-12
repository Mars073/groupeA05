#include "Heal.h"


Heal::Heal(std::string itemName,std::string itemDescription,int amountHealed):Item(itemName,itemDescription)
{
    itemType="Heal";
    this->amountHealed=amountHealed;
}

Heal::~Heal()
{

}

Heal::Heal(const Heal& h):Item(itemName,itemDescription)
{
    itemType="Heal";
    this->amountHealed=h.amountHealed;
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
