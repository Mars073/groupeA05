#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <map>
#include <string.h>
#include<SFML/Graphics.hpp>

using std::string;
using std::map;
using std::pair;
using sf::Font;
using sf::Texture;

class Ressources
{
    private:
        /** Cache :: */
        static map<string, Font> fonts;
        static map<string, Texture> textures;
        Ressources();// Disallow creating an instance

    public:
        static Font getFont(string, string);
        static Texture getTexture(string, string);

};

#endif // RESSOURCES_H
