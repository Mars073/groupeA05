#ifndef SCENE_H
#define SCENE_H

#include <string.h>
#include <SFML/Graphics.hpp>
#include "Ressources.h"

using namespace std;
using namespace sf;

class Scene : public Drawable
{
    private:

    public:
        Scene();
        ~Scene();
        bool controller = true;
        // /!\ crée une abstraction au niveau de la classe
        virtual void draw(RenderTarget&, RenderStates)const = 0;
        virtual void eventHandler(Event) = 0;

        // raccourcis scene <-> game
        RenderWindow* getWindow();
        void setScene(Scene*);

};

#endif // SCENE_H
