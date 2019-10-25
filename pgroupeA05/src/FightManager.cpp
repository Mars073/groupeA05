#include "FightManager.h"

FightManager::FightManager()
{
    //ctor
    setPlayer(new Player("joueur",5,5,5,5,5));
    setMonster(new Monster("monstre",5,5,5,5,10,1,100,100));
}

FightManager::~FightManager()
{
    //dtor
    delete(ms);
    delete(pl);
}
void FightManager::DamagePlayer()
{
    //no finsh calcul
    ms->damageReceived(pl->damageDone());

}
void FightManager::DamageMonster()
{
 pl->damageDone();
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

