#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H

#include<Monster.h>
#include<Player.h>
#include "Model/SingletonGame.h"

class FightManager
{
    public:
        FightManager();
        virtual ~FightManager();
        void drawButton();
        void DamagePlayer();
        void DamageMonster();
        void setPlayer(Player *pls);
        void setMonster(Monster *ms);
        Player* getPlayer()const;
        Monster* getMonster()const;
        void DamageMagicPlayer(Magic *Magic);

    protected:

    private:
        //*FightScene;
        //Monster who fight
        Monster *ms;
        //Player
        Player *pl;

};

#endif // FIGHTMANAGER_H
