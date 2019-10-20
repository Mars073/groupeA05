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

void Bestiary::changeAttribute(std::string nameMonster,std::string nameAttribute,std::string val)
{
    if(getOneMonster(val)==0){
        getOneMonster(nameMonster)->SetcharaName(val);
        writeInFile();
    }
}

void Bestiary::changeAttribute(std::string nameMonster,std::string nameAttribute,int val)
{
    if(nameAttribute=="hp"){
        getOneMonster(nameMonster)->Sethp(val);
    }
    else if(nameAttribute=="mp"){
        getOneMonster(nameMonster)->Setmp(val);
    }
    else if(nameAttribute=="atk"){
        getOneMonster(nameMonster)->Setatk(val);
    }
    else if(nameAttribute=="mag"){
        getOneMonster(nameMonster)->Setmag(val);
    }
    else if(nameAttribute=="def"){
        getOneMonster(nameMonster)->Setdef(val);
    }
    else if(nameAttribute=="level"){
        getOneMonster(nameMonster)->Setlevel(val);
    }
    else if(nameAttribute=="money"){
        getOneMonster(nameMonster)->SetmoneyHeld(val);
    }
    else if(nameAttribute=="exp"){
        getOneMonster(nameMonster)->SetexpHeld(val);
    }

    writeInFile();
}

void Bestiary::deleteMonster(std::string nameMonster)
{
    bestiary.remove(getOneMonster(nameMonster));
    writeInFile();
}
