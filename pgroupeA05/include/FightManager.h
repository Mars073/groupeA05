#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H


class FightManager
{
    public:
        FightManager();
        virtual ~FightManager();
        void drawButton();
        void DamagePlayer();
        void DamageMonster();

    protected:

    private:
        //*FightScene;
        //Monster who fight
        Monster *ms;
        //Player
        Player *pl;

};

#endif // FIGHTMANAGER_H
