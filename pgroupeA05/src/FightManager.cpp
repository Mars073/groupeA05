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
Monster* FightManager::getMonster()const
{
 return ms;
}
Player* FightManager::getPlayer()const
{
 return pl;
}
void FightManager::setMonster(Monster* ms)
{
  this->ms = ms;
}
void FightManager::setPlayer(Player* pls)
{
  this->pl = (SingletonGame::getInstance()->getPlayerPTR());
  if(!this->pl)
  {
   //fuite de emoire pour l'instant
   this->pl = pls;
  }

}

