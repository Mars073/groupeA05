#include "Spells.h"

Spells::Spells()
{
    readFromFile();
}

Spells::~Spells()
{
    for (unsigned i = 0; i < spellsHeld.size(); i++)
    {
        delete spellsHeld.at(i);
    }

    for (unsigned i = 0; i < everySpells.size(); i++)
    {
        delete everySpells.at(i);
    }
}

Spells::Spells(const Spells& s)
{
    readFromFile();
}

Spells& Spells::operator=(const Spells& s)
{
    if(this!=&s){
        for (unsigned i = 0; i < spellsHeld.size(); i++)
        {
            delete spellsHeld.at(i);
            spellsHeld.at(i)=s.spellsHeld.at(i)->clone();
        }

        for (unsigned i = 0; i < everySpells.size(); i++)
        {
            delete everySpells.at(i);
            everySpells.at(i)=s.everySpells.at(i)->clone();
        }
        readFromFile();
    }
    return *this;
}

void Spells::addMagic(Magic *magic)
{
    if (indexOf(magic) >= 0){
        return;
    }
    spellsHeld.push_back(magic->clone());
}

void Spells::addMagic(std::string magicName)
{
    if (indexOf(getOneMagic(magicName)) >= 0){
        return;
    }
    spellsHeld.push_back(getOneMagic(magicName)->clone());
}

void Spells::addMagicInFile(Magic *magic)
{
    if (indexOfEverySpells(magic) >= 0){
        return;
    }
    everySpells.push_back(magic);
    writeInFile();
}

int Spells::indexOf(Magic* magic) const
{
    for (unsigned i = 0; i < spellsHeld.size(); i++){
        if (*(spellsHeld.at(i)) == *magic){
            return i;
        }
    }
    return -1;
}

int Spells::indexOfEverySpells(Magic* magic) const
{
    for (unsigned i = 0; i < everySpells.size(); i++){
        if (*(everySpells.at(i)) == *magic){
            return i;
        }
    }
    return -1;
}

std::vector<Magic*> Spells::GetspellsHeld() const
{
    std::vector<Magic*>clone;
    for (unsigned i = 0; i < spellsHeld.size(); i++){
        clone.push_back(spellsHeld.at(i)->clone());
    }
    return clone;
}

std::vector<Magic*> Spells::GeteverySpells() const
{
    return everySpells;
}

std::string Spells::str() const
{
    std::stringstream sstr;
    sstr<<"Spells : " <<std::endl<<std::endl;
    for (auto const& i : spellsHeld){
        sstr<<i->str()<<std::endl;
    }

    return sstr.str();
}

void Spells::readFromFile()
{
    std::string magicName;
    int magicDamage,magicMpUsage;
    std::ifstream infile;
    infile.open ("data/lists/spells.txt");

    if(infile){
        while ( !infile.eof() )
        {
            std::getline(infile,magicName,'/');
            infile>>magicDamage>>magicMpUsage;
            everySpells.push_back(new Magic(magicName,magicDamage,magicMpUsage));
            //for windows
            //infile.ignore();
        }
    }
    infile.close();
}

void Spells::writeInFile()
{
    std::ofstream output("data/lists/spells.txt");

	for (auto const& i : everySpells)
	{
        output<<i->GetmName()<<"/"<<i->GetbaseDamage()<<i->GetmpUsage();
        //for windows
        /*if (&i != &everySpells.back()){
            output<<std::endl;
        }*/
	}
}

Magic* Spells::getOneMagic(std::string name)
{
    for (unsigned i = 0; i < everySpells.size(); i++){
        if(everySpells.at(i)->GetmName()==name){
            return everySpells.at(i)->clone();
        }
    }
    return new Magic("Ice",10,10);
}

Magic* Spells::getOneMagicInGame(std::string name)
{
    for (unsigned i = 0; i < spellsHeld.size(); i++){
        if(spellsHeld.at(i)->GetmName()==name){
            return spellsHeld.at(i);
        }
    }
    return new Magic("Ice",10,10);
}


void Spells::changeAttribute(std::string nameMagic,std::string nameAttribute,std::string val)
{
    if(nameAttribute=="name"){
        if(getOneMagic(val)==0){
            getOneMagic(nameMagic)->SetmName(val);
        }
    }
    writeInFile();
}

void Spells::changeAttribute(std::string nameMagic,std::string nameAttribute,int val)
{
    if(nameAttribute=="damage"){
        getOneMagic(nameMagic)->SetbaseDamage(val);
    }
    else if(nameAttribute=="mp usage"){
        getOneMagic(nameMagic)->SetmpUsage(val);
    }
    writeInFile();
}

void Spells::deleteMagic(std::string nameMagic)
{
    int tmp = indexOf(getOneMagic(nameMagic));
    if (tmp < 0){
        return;
    }
    delete spellsHeld.at(tmp);
    spellsHeld.erase(spellsHeld.begin() + tmp);
}

void Spells::deleteMagicInFile(std::string nameMagic)
{
    int tmp = indexOf(getOneMagic(nameMagic));
    if (tmp < 0){
        return;
    }
    delete everySpells.at(tmp);
    everySpells.erase(everySpells.begin() + tmp);
    writeInFile();
}
