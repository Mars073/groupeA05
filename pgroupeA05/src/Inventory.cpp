#include "Inventory.h"


Inventory::Inventory()
{
    readFromFile();
}

Inventory::~Inventory()
{
    for (auto const& i : bag){
        delete i;
    }
    for (auto const& i : everyItems){
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
        for (auto const& i : everyItems){
            delete i;
        }
    }
    return *this;
}

void Inventory::addItem(Item *item)
{
    bag.push_back(item);
}

void Inventory::addItem(std::string itemName)
{
    bag.push_back(getOneItem(itemName));
}

void Inventory::addItemInFile(Item *item)
{
    if(getOneItem(item->GetitemName())==0){
        everyItems.push_back(item);
        writeInFile();
    }

}

std::list<Item*> Inventory::Getbag() const
{
    return bag;
}

std::string Inventory::str() const
{
    std::stringstream sstr;
    sstr<<"Items : " <<std::endl<<std::endl;
    for (auto const& i : bag){
        sstr<<i->str()<<std::endl;
    }

    return sstr.str();
}

void Inventory::readFromFile()
{
    std::string iItemName,iItemDescription;
    int hAmountHealed,aDef,wAtk,wMag;
    std::ifstream infile;
    infile.open ("data/lists/heals.txt");

    if(infile){
        while ( !infile.eof() )
        {
            std::getline(infile,iItemName,'/');
            std::getline(infile,iItemDescription,'/');
            infile>>hAmountHealed;
            everyItems.push_back(new Heal(iItemName,iItemDescription,hAmountHealed));
            infile.ignore();
        }
    }
    infile.close();

    infile.open ("data/lists/armors.txt");

    if(infile){
        while ( !infile.eof() )
        {
            std::getline(infile,iItemName,'/');
            std::getline(infile,iItemDescription,'/');
            infile>>aDef;
            everyItems.push_back(new Armor(iItemName,iItemDescription,aDef));
            infile.ignore();
        }
    }
    infile.close();

    infile.open ("data/lists/weapons.txt");

    if(infile){
        while ( !infile.eof() )
        {
            std::getline(infile,iItemName,'/');
            std::getline(infile,iItemDescription,'/');
            infile>>wAtk;
            infile>>wMag;
            everyItems.push_back(new Weapon(iItemName,iItemDescription,wAtk,wMag));
            infile.ignore();
        }
    }
    infile.close();

}

void Inventory::writeInFile()
{
    std::ofstream output("data/lists/heals.txt");
    std::ofstream output2("data/lists/armors.txt");
    std::ofstream output3("data/lists/weapons.txt");
    bool checkHeal=false;
    bool checkArmor=false;
    bool checkWeapon=false;

	for (auto const& i : everyItems)
	{
	    if(i->GetitemType()=="Heal"){
            Heal *d = dynamic_cast<Heal*>(i);
            if(checkHeal){
                output<<std::endl;
            }
            else{
                checkHeal=true;
            }
            output<<d->GetitemName()<<"/"<<d->GetitemDescription()<<"/"<<d->GetamountHealed();
	    }
	    else if(i->GetitemType()=="Armor"){
            Armor *d = dynamic_cast<Armor*>(i);
            if(checkArmor){
                output2<<std::endl;
            }
            else{
                checkArmor=true;
            }
            output2<<d->GetitemName()<<"/"<<d->GetitemDescription()<<"/"<<d->Getdef();
	    }
	    else if(i->GetitemType()=="Weapon"){
            Weapon *d = dynamic_cast<Weapon*>(i);
            if(checkWeapon){
                output3<<std::endl;
            }
            else{
                checkWeapon=true;
            }
            output3<<d->GetitemName()<<"/"<<d->GetitemDescription()<<"/"<<d->Getatk()<<" "<<d->Getmag();
	    }
	}
}

Item* Inventory::getOneItem(std::string name)
{
    for (auto const& i : everyItems){
        if(i->GetitemName()==name){
            return i;
        }
    }
    return 0;
}

void Inventory::changeAttribute(std::string nameItem,std::string nameAttribute,std::string val)
{
    if(nameAttribute=="name"){
        if(getOneItem(val)==0){
            getOneItem(nameItem)->SetitemName(val);
        }
    }
    else if(nameAttribute=="description"){
        getOneItem(nameItem)->SetitemDescription(val);
    }
    writeInFile();
}

void Inventory::changeAttribute(std::string nameItem,std::string nameAttribute,int val)
{
    if(getOneItem(nameItem)->GetitemType()=="Heal"){
        if(nameAttribute=="heal"){
            dynamic_cast<Heal*>(getOneItem(nameItem))->SetamountHealed(val);
        }
    }
    else if(getOneItem(nameItem)->GetitemType()=="Armor"){
        if(nameAttribute=="def"){
            dynamic_cast<Armor*>(getOneItem(nameItem))->Setdef(val);
        }
    }
    else if(getOneItem(nameItem)->GetitemType()=="Weapon"){
        if(nameAttribute=="atk"){
            dynamic_cast<Weapon*>(getOneItem(nameItem))->Setatk(val);
        }
        else if(nameAttribute=="mag"){
            dynamic_cast<Weapon*>(getOneItem(nameItem))->Setmag(val);
        }
    }

    writeInFile();
}

void Inventory::deleteItem(std::string nameItem)
{
    bag.remove(getOneItem(nameItem));
}

void Inventory::deleteItemInFile(std::string nameItem)
{
    everyItems.remove(getOneItem(nameItem));
    writeInFile();
}
