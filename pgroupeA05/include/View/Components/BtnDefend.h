#ifndef BTNDEFEND_H
#define BTNDEFEND_H
#include "string"
#include "iostream"
#include "BtnWin.h"


class BtnDefend : public BtnWin
{
 public:
        BtnDefend(int positionX = 0,int positionY = 0,int tailleX = 0,int tailleY = 0,std::string textButton="");
        BtnDefend(BtnDefend const &btnA);
        BtnDefend& operator=(const BtnDefend& c);
        //Action that the button make
        void action();
        virtual ~BtnDefend();
        std::string getDescription();
        BtnDefend *clone();


 protected:

 private:
};

#endif // BTNDEFEND_H
