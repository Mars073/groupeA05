#ifndef WINDOWSFIGHTINFO_H
#define WINDOWSFIGHTINFO_H
#include "WindowsFight.h"



class WindowsFightInfo:public WindowsFight
{
    public:
        WindowsFightInfo(int posX,int posY,int sizeX,int sizeY);
        void EcrireinWindow();
        virtual ~WindowsFightInfo();

    protected:

    private:

};

#endif // WINDOWSFIGHTINFO_H
