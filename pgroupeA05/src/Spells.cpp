#include "Spells.h"

Spells::Spells()
{
    readFromFile();
}

Spells::~Spells()
{
    for (auto const& i : spellsHeld){
        delete i;
    }
    for (auto const& i : everySpells){
        delete i;
    }
}

Spells::Spells(const Spells& s)
{
    //copy ctor
}

Spells& Spells::operator=(const Spells& s)
{
    if(this!=&s){
        for (auto const& i : spellsHeld){
            delete i;
        }
        for (auto const& i : everySpells){
            delete i;
        }
    }
    return *this;
}

void Spells::addMagic(Magic *magic)
{
    spellsHeld.push_back(magic);
}

void Spells::addMagic(std::string magicName)
{
    spellsHeld.push_back(getOneMagic(magicName));
}

void Spells::addMagicInFile(Magic *magic)
{
    if(getOneMagic(magic->GetmName())==0){
        everySpells.push_back(magic);
        writeInFile();
    }

}

std::list<Magic*> Spells::GetspellsHeld() const
{
    return spellsHeld;
}

std::list<Magic*> Spells::GeteverySpells() const
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
    int magicDamage;
    std::ifstream infile;
    infile.open ("data/lists/spells.txt");

    if(infile){
        while ( !infile.eof() )
        {
            std::getline(infile,magicName,'/');
            infile>>magicDamage;
            everySpells.push_back(new Magic(magicName,magicDamage));
            infile.ignore();
        }
    }
    infile.close();
}

void Spells::writeInFile()
{
    std::ofstream output("data/lists/spells.txt");

	for (auto const& i : everySpells)
	{
        output<<i->GetmName()<<"/"<<i->GetbaseDamage();
        if (&i != &everySpells.back()){
            output<<std::endl;
        }
	}
}

Magic* Spells::getOneMagic(std::string name)
{
    for (auto const& i : everySpells){
        if(i->GetmName()==name){
            return i;
        }
    }
    return 0;
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
    writeInFile();
}

void Spells::deleteMagic(std::string nameMagic)
{
    spellsHeld.remove(getOneMagic(nameMagic));
}

void Spells::deleteMagicInFile(std::string nameMagic)
{
    everySpells.remove(getOneMagic(nameMagic));
    writeInFile();
}
