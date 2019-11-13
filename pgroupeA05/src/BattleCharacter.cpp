#include "BattleCharacter.h"

BattleCharacter::BattleCharacter(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def):Character(charaName)
{
    this->maxHp=maxHp;
    this->hp=hp;
    this->maxMp=maxMp;
    this->mp=mp;
    this->atk=atk;
    this->mag=mag;
    this->def=def;
}

BattleCharacter::~BattleCharacter()
{
    //dtor
}

BattleCharacter::BattleCharacter(const BattleCharacter& b):Character(b)
{
    this->maxHp=b.maxHp;
    this->hp=b.hp;
    this->maxMp=b.maxMp;
    this->mp=b.mp;
    this->atk=b.atk;
    this->mag=b.mag;
    this->def=b.def;
}

BattleCharacter& BattleCharacter::operator=(const BattleCharacter& b){
    if(this!=&b){
        this->maxHp=b.maxHp;
        this->hp=b.hp;
        this->maxMp=b.maxMp;
        this->mp=b.mp;
        this->atk=b.atk;
        this->mag=b.mag;
        this->def=b.def;
    }
    return *this;
}


int BattleCharacter::Getlevel() const
{
    return level;
}

void BattleCharacter::Setlevel(int val)
{
    level = val;
}

int BattleCharacter::GetmaxHp() const
{
    return maxHp;
}

void BattleCharacter::SetmaxHp(int val)
{
    maxHp = val;
}

int BattleCharacter::Gethp() const
{
    return hp;
}

void BattleCharacter::Sethp(int val)
{
    hp = val;
}

int BattleCharacter::GetmaxMp() const
{
    return maxMp;
}

void BattleCharacter::SetmaxMp(int val)
{
    maxMp = val;
}

int BattleCharacter::Getmp() const
{
    return mp;
}

void BattleCharacter::Setmp(int val)
{
    mp = val;
}

int BattleCharacter::Getatk() const
{
    return atk;
}

void BattleCharacter::Setatk(int val)
{
    atk = val;
}

int BattleCharacter::Getmag() const
{
    return mag;
}

void BattleCharacter::Setmag(int val)
{
    mag = val;
}

int BattleCharacter::Getdef() const
{
    return def;
}

void BattleCharacter::Setdef(int val)
{
    def = val;
}

std::string BattleCharacter::str() const
{
    std::stringstream sstr;
    sstr<<Character::str()<<std::endl
    <<"Level : "<<Getlevel()<<std::endl
    <<"Hp : "<<Gethp()<<"/"<<GetmaxHp()<<std::endl
    <<"Mp : "<<Getmp()<<"/"<<GetmaxMp()<<std::endl
    <<"Atk : "<<Getatk()<<std::endl
    <<"Mag : "<<Getmag()<<std::endl
    <<"Def : "<<Getdef();
    return sstr.str();
}

std::string BattleCharacter::strHp() const
{
    std::stringstream sstr;
    sstr<<Gethp()<<"/"<<GetmaxHp();
    return sstr.str();
}


BattleCharacter* BattleCharacter::clone() const
{
    return new BattleCharacter(GetcharaName(),GetmaxHp(),Gethp(),GetmaxMp(),Getmp(),Getatk(),Getmag(),Getdef());
}

