#ifndef SCENE_H
#define SCENE_H

#include <map>
#include <string.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Scene
{
    private:
        map<string, Texture> textures;
        map<string, Font> fonts;
    public:
        Scene();
        ~Scene();
        virtual void draw() = 0;    // /!\ crée un abstraction au niveau de la classe
        virtual void eventHandler(Event) = 0;
        Texture getTexture(string, string);
        Font getFont(string, string);

        // raccourcis scene <-> game
        RenderWindow* getWindow();
        void setScene(Scene*);

};

#endif // SCENE_H
