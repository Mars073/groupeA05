#ifndef BTNDEFEND_H
#define BTNDEFEND_H
#include "string"
#include "iostream"
#include "BtnWin.h"


class BtnDefend : public BtnWin
{
 public:
        BtnDefend(int positionX,int positionY,int tailleX,int tailleY,std::string textButton);
        BtnDefend(BtnDefend const &btnA);
        //Action that the button make
        void action();
        virtual ~BtnDefend();
        std::string getDescription();
        BtnDefend *clone();


 protected:

 private:
};

#endif // BTNDEFEND_H
