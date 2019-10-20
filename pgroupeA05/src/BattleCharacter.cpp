#include "BattleCharacter.h"

BattleCharacter::BattleCharacter(std::string charaName,int hp,int mp,int atk,int mag,int def):Character(charaName)
{
    this->hp=hp;
    this->mp=mp;
    this->atk=atk;
    this->mag=mag;
    this->def=def;
}

BattleCharacter::~BattleCharacter()
{
    //dtor
}

BattleCharacter::BattleCharacter(const BattleCharacter& b):Character(charaName)
{
    this->hp=b.hp;
    this->mp=b.mp;
    this->atk=b.atk;
    this->mag=b.mag;
    this->def=b.def;
}

BattleCharacter& BattleCharacter::operator=(const BattleCharacter& b){
    if(this!=&b){
        this->hp=b.hp;
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

int BattleCharacter::Gethp() const
{
    return hp;
}

void BattleCharacter::Sethp(int val)
{
    hp = val;
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
    sstr<<Character::str()<<std::endl<<"level : "<<Getlevel()<<std::endl<<"hp : "<<Gethp()<<std::endl<<"mp : "<<Getmp()<<std::endl<<"atk : "<<Getatk()<<std::endl<<"mag : "<<Getmag()<<std::endl<<"def : "<<Getdef();
    return sstr.str();
}

