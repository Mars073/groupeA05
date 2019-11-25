#ifndef BTNATTACK_H
#define BTNATTACK_H
#include "BtnWin.h"
#include "string"

class btnAttack : public BtnWin
{
    public:
        btnAttack(int positionX = 0,int positionY= 0,int tailleX = 0,int tailleY = 0,std::string textButton="");
        btnAttack(btnAttack const &btnA);
        btnAttack& operator=(const btnAttack& c);
        //Action that the button make
        void action();
        virtual ~btnAttack();
        std::string getDescription();
        btnAttack *clone();


    protected:

    private:
};

#endif // BTNATTACK_H
