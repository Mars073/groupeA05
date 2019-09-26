#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

class Scene
{
    private:

    public:
        Scene();
        virtual void eventHandler(sf::Event) {};
        virtual void draw() {};
};

#endif // SCENE_H
