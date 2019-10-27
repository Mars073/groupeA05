#include "FightManager.h"

FightManager::FightManager()
{
    //ctor
    setPlayer(new Player());
    setMonster(new Monster("monstre",500,500,500,1,10,1,100,100));
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
    if(!pl)
    {
       std::cout <<"il y a pas de player"<<endl;
    }
    if(!ms)
    {
        std::cout <<"il y a pas de monstre"<<endl;
    }
    std::cout <<pl->damageDone()<<" nombre de domage du joueur"<<endl;
    ms->damageReceived(pl->damageDone());
    this->DamageMonster();

}
void FightManager::DamageMonster()
{
 if(!pl)
    {
       std::cout <<"il y a pas de player"<<endl;
    }
    if(!ms)
    {
        std::cout <<"il y a pas de monstre"<<endl;
    }
 pl->damageReceived(ms->damageDone());
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

