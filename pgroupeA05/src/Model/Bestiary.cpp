#include "Bestiary.h"

Bestiary::Bestiary()
{
    this->inventory=new Inventory();
    readFromFile();
}

Bestiary::~Bestiary()
{
    for (unsigned i = 0; i < bestiary.size(); i++)
    {
        delete bestiary.at(i);
    }
    delete inventory;
}

Bestiary::Bestiary(const Bestiary& b)
{
    this->inventory=new Inventory(*b.inventory);
    readFromFile();
}

Bestiary& Bestiary::operator=(const Bestiary& b){
    if(this!=&b){
        for (unsigned i = 0; i < bestiary.size(); i++)
        {
            delete bestiary.at(i);
            bestiary.at(i)=b.bestiary.at(i)->clone();
        }
        delete inventory;
        this->inventory=new Inventory(*b.inventory);
        readFromFile();
    }
    return *this;
}

void Bestiary::addMonster(Monster *monster)
{
    if (indexOf(monster) >= 0){
        return;
    }
    bestiary.push_back(monster);
    writeInFile();

}

int Bestiary::indexOf(Monster *monster) const
{
    for (unsigned i = 0; i < bestiary.size(); i++){
        if (*(bestiary.at(i)) == *monster){
            return i;
        }
    }
    return -1;
}

std::vector<Monster*> Bestiary::Getbestiary() const
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
    std::string mCharaName,itemName;
    int  mMaxHp, mHp,mMaxMp,mMp, mAtk, mMag, mDef, mLevel, mExpHeld,nbItem,percentItem;
    std::vector<std::string>itemsName;
    std::vector<int>percentsItem;
    std::ifstream infile;
    infile.open ("data/lists/bestiary.txt");

    if(infile){
        while ( !infile.eof() )
        {
            itemsName.clear();
            percentsItem.clear();
            std::getline(infile,mCharaName,'/');
            infile >>mMaxHp>>mHp>>mMaxMp>>mMp>>mAtk>>mMag>>mDef>>mLevel>>mExpHeld>>nbItem;
            for(int i=0;i<nbItem;i++){
                std::getline(infile,itemName,'/');
                itemsName.push_back(itemName);
                infile>>percentItem;
                percentsItem.push_back(percentItem);
            }
            Monster* m=new Monster(mCharaName,mMaxHp,mHp,mMaxMp,mMp,mAtk,mMag,mDef,mLevel,mExpHeld);
            for(int i=0;i<nbItem;i++){
                m->addLoot(inventory->getOneItem(itemsName[i])->clone());
                m->addPercentage(percentsItem[i]);


            }

            bestiary.push_back(m);
            //allows to ignore the blank space between monsters in the file
            infile.ignore();
        }
    }
    infile.close();

}

void Bestiary::writeInFile()
{
    std::ofstream output("data/lists/bestiary.txt");

	for (auto const& i : bestiary)
	{
        output<<i->GetcharaName()<<"/"<<i->GetmaxHp()<<i->Gethp()<<" "<<i->GetmaxMp()<<" "<<i->Getmp()<<" "<<i->Getatk()<<" "<<i->Getmag()<<" "<<i->Getdef()<<" "<<i->Getlevel()<<" "<<i->GetexpHeld()<<" "<<i->GetPercentagesItem().size();
        for(int j=0;j<i->GetPercentagesItem().size();j++){
            output<<i->GetLootHeld().at(j)->GetitemName()<<"/"<<i->GetPercentagesItem().at(j);
        }
        if (&i != &bestiary.back()){
            output<<std::endl;
        }
	}
}

Monster* Bestiary::getOneMonster(std::string name) const
{
    for (unsigned i = 0; i < bestiary.size(); i++){
        if(bestiary.at(i)->GetcharaName()==name){
            return bestiary.at(i)->clone();
        }
    }
    return new Monster("Goblin",20,20,10,10,5,5,5,1,5);
}

void Bestiary::changeAttribute(std::string nameMonster,std::string nameAttribute,std::string val)
{
    if(nameAttribute=="name"){
        if(getOneMonster(val)==0){
            getOneMonster(nameMonster)->SetcharaName(val);
            writeInFile();
        }
    }

}

void Bestiary::changeAttribute(std::string nameMonster,std::string nameAttribute,int val)
{
    if(nameAttribute=="max hp"){
        getOneMonster(nameMonster)->SetmaxHp(val);
    }
    else if(nameAttribute=="hp"){
        getOneMonster(nameMonster)->Sethp(val);
    }
    else if(nameAttribute=="max mp"){
        getOneMonster(nameMonster)->SetmaxMp(val);
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
    else if(nameAttribute=="exp"){
        getOneMonster(nameMonster)->SetexpHeld(val);
    }

    writeInFile();
}

void Bestiary::deleteMonster(std::string nameMonster)
{
    int tmp = indexOf(getOneMonster(nameMonster));
    if (tmp < 0){
        return;
    }
    delete bestiary.at(tmp);
    bestiary.erase(bestiary.begin() + tmp);
    writeInFile();
}

Monster* Bestiary::getOneRandomMonster() const{
    srand(time(NULL));
    return bestiary.at(rand() % (bestiary.size()-1) + 0);
}
