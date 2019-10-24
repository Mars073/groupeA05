#include "FightManager.h"

FightManager::FightManager()
{
    //ctor
}

FightManager::~FightManager()
{
    //dtor
    delete(ms);
}
void FightManager::DamagePlayer()
{
    //no finsh calcul

}
void FightManager::DamageMonster()
{

}
void FightManager::setMonster(Monster* ms)
{
  this->ms = ms;
}
void FightManager::setPlayer(Player* pls)
{
  this->pl = pl;
}

