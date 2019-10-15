#include "Resources.h"

map<string, Font> Resources::fonts;
map<string, Texture> Resources::textures;

Resources::Resources()
{
    // ctor
}

Font Resources::getFont(string name, string filename)
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

Texture Resources::getTexture(string name, string filename)
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
