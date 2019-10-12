#include "Bestiary.h"

Bestiary::Bestiary()
{
    readFromFile();
}

Bestiary::~Bestiary()
{
    //dtor
}

Bestiary::Bestiary(const Bestiary& b)
{
    //copy ctor
}

void Bestiary::addMonster(Monster *monster)
{
    bestiary.push_back(monster);
    //writeInFile(monster);

}

std::list<Monster*> Bestiary::Getbestiary() const
{
    return bestiary;
}

std::string Bestiary::str() const
{
    std::stringstream sstr;
    //std::list<Item>::iterator it;
    sstr<<"Bestiary : " <<std::endl<<std::endl;
    for (auto const& i : bestiary){
        //sstr<<it->str()<<endl;
        sstr<<i->str()<<std::endl;
    }

    return sstr.str();
}

void Bestiary::readFromFile()
{
    std::string mcharaName;
    int mhp, mmp, matk, mmag, mdef, mlevel, mmoneyHeld, mexpHeld;
    std::ifstream infile;
    infile.open ("data/lists/bestiary.txt");

    if(infile){
        while ( !infile.eof() )
        {
            infile >> mcharaName>>mhp>>mmp>>matk>>mmag>>mdef>>mlevel>>mmoneyHeld>>mexpHeld;

            addMonster(new Monster(mcharaName,mhp,mmp,matk,mmag,mdef,mlevel,mmoneyHeld,mexpHeld));

        }
    }
    infile.close();

}

void Bestiary::writeInFile(Monster* monster)
{
    // Object to write in file
    std::ofstream file_obj;

    // Opening file in append mode
    file_obj.open("data/lists/bestiary.txt", std::ios::app);

    // Writing the object's data in file
    file_obj.write((char*)&monster, sizeof(monster));

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
