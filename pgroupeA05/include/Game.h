#ifndef GAME_H
#define GAME_H

#include "HomeScene.h"

using namespace sf;

class Game
{
    private:
        static Game* instance; // singleton
        Game();
        Scene* scene = new HomeScene;
        RenderWindow *window = nullptr;

    public:
        static Game* getInstance();
        virtual ~Game();

        void draw();
        RenderWindow* getWindow();
        void setScene(Scene*);
        Scene* getScene();

        // raccourcis game <-> window
        bool isOpen();
        bool pollEvent(Event&);
        void pollEvent();
        void close();
        void test_com();

};

#endif // GAME_H
