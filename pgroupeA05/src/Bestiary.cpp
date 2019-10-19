#include "Bestiary.h"

Bestiary::Bestiary()
{
    readFromFile();
}

Bestiary::~Bestiary()
{
    for (auto const& i : bestiary){
        delete i;
    }
}

Bestiary::Bestiary(const Bestiary& b)
{
    //copy ctor
}

Bestiary& Bestiary::operator=(const Bestiary& b){
    if(this!=&b){
        for (auto const& i : bestiary){
            delete i;
        }
    }
    return *this;
}

void Bestiary::addMonster(Monster *monster)
{
    if(getOneMonster(monster->GetcharaName())==0){
        bestiary.push_back(monster);
        writeInFile();
    }

}

std::list<Monster*> Bestiary::Getbestiary() const
{
    return bestiary;
}

std::string Bestiary::str() const
{
    std::stringstream sstr;

    sstr<<"Bestiary : " <<std::endl<<std::endl;
    for (auto const& i : bestiary){
        sstr<<i->str()<<std::endl;
    }

    return sstr.str();
}

void Bestiary::readFromFile()
{
    std::string mCharaName;
    int mHp, mMp, mAtk, mMag, mDef, mLevel, mMoneyHeld, mExpHeld;
    std::ifstream infile;
    infile.open ("data/lists/bestiary.txt");

    if(infile){
        while ( !infile.eof() )
        {
            infile >> mCharaName>>mHp>>mMp>>mAtk>>mMag>>mDef>>mLevel>>mMoneyHeld>>mExpHeld;

            bestiary.push_back(new Monster(mCharaName,mHp,mMp,mAtk,mMag,mDef,mLevel,mMoneyHeld,mExpHeld));
        }
    }
    infile.close();

}

void Bestiary::writeInFile()
{
    std::ofstream output("data/lists/bestiary.txt");

	for (auto const& i : bestiary)
	{
        output<<i->GetcharaName()<<" "<<i->Gethp()<<" "<<i->Getmp()<<" "<<i->Getatk()<<" "<<i->Getmag()<<" "<<i->Getdef()<<" "<<i->Getlevel()<<" "<<i->GetmoneyHeld()<<" "<<i->GetexpHeld();
        if (&i != &bestiary.back()){
            output<<std::endl;
        }
	}
}

Monster* Bestiary::getOneMonster(std::string name)
{
    for (auto const& i : bestiary){
        if(i->GetcharaName()==name){
            return i;
        }
    }
    return 0;
}

void Bestiary::changeAttribute(std::string nameMonster,std::string nameAttribute,std::string value)
{
    getOneMonster(nameMonster)->SetcharaName(value);
    writeInFile();
}

void Bestiary::changeAttribute(std::string nameMonster,std::string nameAttribute,int value)
{
    if(nameAttribute=="hp"){
        getOneMonster(nameMonster)->Sethp(value);
    }
    else if(nameAttribute=="mp"){
        getOneMonster(nameMonster)->Setmp(value);
    }
    else if(nameAttribute=="atk"){
        getOneMonster(nameMonster)->Setatk(value);
    }
    else if(nameAttribute=="mag"){
        getOneMonster(nameMonster)->Setmag(value);
    }
    else if(nameAttribute=="def"){
        getOneMonster(nameMonster)->Setdef(value);
    }
    else if(nameAttribute=="level"){
        getOneMonster(nameMonster)->Setlevel(value);
    }
    else if(nameAttribute=="money"){
        getOneMonster(nameMonster)->SetmoneyHeld(value);
    }
    else if(nameAttribute=="exp"){
        getOneMonster(nameMonster)->SetexpHeld(value);
    }

    writeInFile();
}

void Bestiary::deleteMonster(std::string nameMonster)
{
    bestiary.remove(getOneMonster(nameMonster));
    writeInFile();
}
