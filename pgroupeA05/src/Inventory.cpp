#include "Inventory.h"


Inventory::Inventory()
{
    readFromFile();
}

Inventory::~Inventory()
{
    for (unsigned i = 0; i < bag.size(); i++)
    {
        delete bag.at(i);
    }

    for (unsigned i = 0; i < everyItems.size(); i++)
    {
        delete everyItems.at(i);
    }
}

Inventory::Inventory(const Inventory& i)
{
    readFromFile();
}

Inventory& Inventory::operator=(const Inventory& i){
    if(this!=&i){
        for (unsigned i = 0; i < bag.size(); i++)
        {
            delete bag.at(i);
        }

        for (unsigned i = 0; i < everyItems.size(); i++)
        {
            delete everyItems.at(i);
        }
        readFromFile();
    }
    return *this;
}

void Inventory::addItem(Item* item)
{
    /*if (indexOf(item) >= 0){
        return;
    }*/
    bag.push_back(item->clone());
}


void Inventory::addItem(std::string itemName)
{
    /*if (indexOf(getOneItem(itemName)->clone()) >= 0){
        return;
    }*/
    bag.push_back(getOneItem(itemName)->clone());
}

void Inventory::addItemInFile(Item* item)
{
    if (indexOfEveryItems(item) >= 0){
        return;
    }
    everyItems.push_back(item);
    writeInFile();
}

int Inventory::indexOf(Item* item) const
{
    for (unsigned i = 0; i < bag.size(); i++){
        if (*(bag.at(i)) == *item){
            return i;
        }
    }
    return -1;
}

int Inventory::indexOfEveryItems(Item* item) const
{
    for (unsigned i = 0; i < everyItems.size(); i++){
        if (*(everyItems.at(i)) == *item){
            return i;
        }
    }
    return -1;
}

std::vector<Item*> Inventory::Getbag() const
{
    return bag;
}

std::vector<Item*> Inventory::GeteveryItems() const
{
    return everyItems;
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
    //for (auto const& i : everyItems){
    for (unsigned i = 0; i < everyItems.size(); i++){
        if(everyItems.at(i)->GetitemName()==name){
            return everyItems.at(i)->clone();
        }
    }
    return 0;
}

Item* Inventory::getOneItemIngame(std::string name)
{
    for (unsigned i = 0; i < bag.size(); i++){
        if(bag.at(i)->GetitemName()==name){
            return bag.at(i);
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
    int tmp = indexOf(getOneItem(nameItem));
    if (tmp < 0){
        return;
    }
    delete bag.at(tmp);
    bag.erase(bag.begin() + tmp);
}

void Inventory::deleteItemInFile(std::string nameItem)
{
    int tmp = indexOf(getOneItem(nameItem));
    if (tmp < 0){
        return;
    }
    delete everyItems.at(tmp);
    everyItems.erase(everyItems.begin() + tmp);
    writeInFile();
}
