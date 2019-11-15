#include "FightManager.h"

FightManager::FightManager()
{
    //ctor
    setPlayer(new Player());
    setMonster(new Monster("monstre",500,500,100,100,1,1,1,1,100,100));


}

FightManager::~FightManager()
{
    //dtor
    delete(ms);

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
void FightManager::DamageMagicPlayer(Magic *magic)
{
    if(!pl)
    {
        std::cout <<"il y a pas de player"<<endl;
    }
    if(!ms)
    {
        std::cout <<"il y a pas de monstre"<<endl;
    }
    std::cout <<pl->damageDone()<<" nombre de domage du joueur"<<endl;
    ms->damageReceived(pl->magicalDamageDone(magic->GetmName()));
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
/** @brief isFightFinish
  *
  * return true if the monster or the player win the battle
  */
bool FightManager::isFightFinish()
{
    if(pl->Gethp() > 0 && ms->Gethp() > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/** @brief isPlayerWin
  *
  * return true if the monster have less 0 hp
  */
bool FightManager::isPlayerWin()
{
    if(ms->Gethp() <= 0)
    {
        //pl->moreExp(ms->GetexpHeld());
        //pl->addLootMonster(ms->giveLoot());
        return true;
    }
    else
    {
        return false;
    }
}

/** @brief WinReward
  *
  * Win to player the reward
  */
void FightManager::WinReward()
{

}



