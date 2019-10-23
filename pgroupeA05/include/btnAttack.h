#ifndef BTNATTACK_H
#define BTNATTACK_H
#include "BtnWin.h"
#include "string"

class btnAttack : public BtnWin
{
    public:
        btnAttack(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
        btnAttack(btnAttack const &btnA);
        //Action that the button make
        void action(Player *pl = nullptr,Monster *ms =nullptr);
        virtual ~btnAttack();


    protected:

    private:
};

#endif // BTNATTACK_H
