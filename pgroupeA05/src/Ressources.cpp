#include "Ressources.h"

map<string, Font> Ressources::fonts;
map<string, Texture> Ressources::textures;

Ressources::Ressources()
{
    // ctor
}

Font Ressources::getFont(string name, string filename)
{
    map<string, Font>::iterator it;
    Font tmp;
    it = fonts.find(name);
    if (it != fonts.end())
        return it->second;
    if (tmp.loadFromFile(filename))
        fonts.insert(pair<string, Font>(name, tmp));
    return tmp;
}

Texture Ressources::getTexture(string name, string filename)
{
    map<string, Texture>::iterator it;
    Texture tmp;
    it = textures.find(name);
    if (it != textures.end())
        return it->second;
    if (tmp.loadFromFile(filename))
        textures.insert(pair<string, Texture>(name, tmp));
    return tmp;
}
