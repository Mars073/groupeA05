#ifndef HOMESCENE_H
#define HOMESCENE_H

#include "Scene.h"

class HomeScene: public Scene
{
    private:
        const string menu[3] = {"PLAY", "CREDITS", "QUIT"};
        const unsigned short int MENU_LENGTH = 3;
        short int selected_id = 0;

    public:
        HomeScene();
        virtual void draw();
        void eventHandler(Event);

};

#endif // HOMESCENE_H
