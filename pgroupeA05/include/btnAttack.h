#ifndef BTNATTACK_H
#define BTNATTACK_H
#include "BtnWin.h"
#include "string"

class btnAttack : public BtnWin
{
    public:
        btnAttack(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
        void action();
        virtual ~btnAttack();


    protected:

    private:
};

#endif // BTNATTACK_H
