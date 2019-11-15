#include "Util/FontsManager.h"

map<string, Font*> FontsManager::store;

FontsManager::FontsManager()
{
    //ctor
}

FontsManager::~FontsManager()
{
    map<string, Font*>::iterator it;
    for (it = store.begin(); it != store.end(); it++)
    {
        delete it->second;
    }
}

FontsManager* FontsManager::getInstance()
{
    static FontsManager instance;
    return &instance;
}

bool FontsManager::load(string name, string filename)
{
    Font font;
    if (!font.loadFromFile(filename))
        return false;
    name = RessourcesManager::str_tolower(name);
    store[name] = new Font(font);
    return true;
}

Font* FontsManager::get(string name) const
{
    map<string, Font*>::iterator it;
    name = RessourcesManager::str_tolower(name);
    it = store.find(name);
    return it->second;
}
