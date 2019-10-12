#include "Monster.h"

Monster::Monster(std::string charaName,int hp,int mp,int atk,int mag,int def,int level,int moneyHeld,int expHeld):BattleCharacter(charaName,hp,mp,atk,mag,def)
{
    charaType="Monster";
    this->level=level;
    this->moneyHeld=moneyHeld;
    this->expHeld=expHeld;
}

Monster::~Monster()
{
    //dtor
}

Monster::Monster(const Monster& m):BattleCharacter(charaName,hp,mp,atk,mag,def)
{
    charaType="Monster";
    this->level=m.level;
    this->moneyHeld=m.moneyHeld;
    this->expHeld=m.expHeld;
}

int Monster::GetmoneyHeld() const
{
    return moneyHeld;
}

void Monster::SetmoneyHeld(int val)
{
    moneyHeld = val;
}

int Monster::GetexpHeld() const
{
    return expHeld;
}

void Monster::SetexpHeld(int val)
{
    expHeld = val;
}

std::string Monster::str() const
{
    std::stringstream sstr;
    sstr<<BattleCharacter::str()<<std::endl<<"money held : "<<GetmoneyHeld()<<std::endl<<"exp held : "<<GetexpHeld()<<std::endl;
    return sstr.str();
}
