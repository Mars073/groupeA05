#ifndef GAME_H
#define GAME_H

#include<Graphics.hpp>
#include<Scene.h>

class Game
{
    private:
        Scene scene;
        static inline Game* singleton = nullptr;
        Game();

    public:
        static inline sf::RenderWindow* window = nullptr;
        static Game* get()
        {
            if (!singleton)
                singleton = new Game;
            return singleton;
        }
        void setScene(Scene);
        Scene getScene();
};

#endif // GAME_H
