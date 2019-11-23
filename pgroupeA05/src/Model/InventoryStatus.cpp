#include "InventoryStatus.h"

InventoryStatus::InventoryStatus()
{
    this->p=SingletonGame::getInstance()->getPlayerPTR();

    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="Weapon"){
            equipments.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }
    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="Armor"){
            equipments.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }

    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="Heal"){
            items.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }

    for (unsigned i = 0; i < p->Getinventory()->Getbag().size(); i++){
        if(p->Getinventory()->Getbag().at(i)->GetitemType()=="HealMp"){
            items.push_back(p->Getinventory()->Getbag().at(i)->clone());
        }
    }
}

InventoryStatus::~InventoryStatus()
{
    for (unsigned i = 0; i < equipments.size(); i++)
    {
        delete equipments.at(i);
    }

    for (unsigned i = 0; i < items.size(); i++)
    {
        delete items.at(i);
    }
}

InventoryStatus::InventoryStatus(const InventoryStatus& other)
{
    this->p=other.p;

    for(unsigned i=0;i<other.equipments.size();i++){
        this->equipments.push_back(other.equipments.at(i)->clone());
    }

    for(unsigned i=0;i<other.items.size();i++){
        this->items.push_back(other.items.at(i)->clone());
    }
}

InventoryStatus& InventoryStatus::operator=(const InventoryStatus& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    this->p=rhs.p;
    for (unsigned i = 0; i < equipments.size(); i++)
    {
        delete equipments.at(i);
        equipments.at(i)=rhs.equipments.at(i)->clone();
    }

    for (unsigned i = 0; i < items.size(); i++)
    {
        delete items.at(i);
        items.at(i)=rhs.items.at(i)->clone();
    }
    return *this;
}

std::vector<Item*> InventoryStatus::Getequipments() const
{
    return equipments;
}

std::vector<Item*> InventoryStatus::Getitems() const
{
    return items;
}

Player* InventoryStatus::Getplayer() const
{
    return p;
}

void InventoryStatus::deleteItem(int index)
{
    delete items.at(index);
    items.erase(items.begin() + index);
}
