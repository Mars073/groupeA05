#ifndef WINDOWSFIGHTINFO_H
#define WINDOWSFIGHTINFO_H
#include "WindowsFight.h"



class WindowsFightInfo:public WindowsFight
{
    public:
        WindowsFightInfo(int posX = 0,int posY = 0,int sizeX = 0,int sizeY = 0);
        void EcrireinWindow();
        virtual ~WindowsFightInfo();
        WindowsFightInfo& operator=(const WindowsFightInfo& rhs);
        WindowsFightInfo(const WindowsFightInfo& other);


    protected:

    private:

};

#endif // WINDOWSFIGHTINFO_H
