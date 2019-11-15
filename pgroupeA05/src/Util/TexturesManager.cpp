#include "Util/TexturesManager.h"

map<string, Texture*> TexturesManager::store;

TexturesManager::TexturesManager()
{
    //ctor
}

TexturesManager::~TexturesManager()
{
    map<string, Texture*>::iterator it;
    for (it = store.begin(); it != store.end(); it++)
    {
        delete it->second;
    }
}

TexturesManager* TexturesManager::getInstance()
{
    static TexturesManager instance;
    return &instance;
}

bool TexturesManager::load(string name, string filename)
{
    Texture texture;
    name = RessourcesManager::str_tolower(name);
    if (!texture.loadFromFile(filename))
        return false;
    store[name] = new Texture(texture);
    return true;
}
Texture* TexturesManager::get(string name) const
{
    map<string, Texture*>::iterator it;
    name = RessourcesManager::str_tolower(name);
    it = store.find(name);
    return it->second;
}
