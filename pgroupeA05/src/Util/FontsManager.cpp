#include "Util/FontsManager.h"

map<string, Font*> FontsManager::store;

FontsManager::FontsManager()
{
    //ctor
}

FontsManager::~FontsManager()
{
    //dtor
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
    store[name] = new Font(font);
    return true;
}

Font* FontsManager::get(string name) const
{
    map<string, Font*>::iterator it;
    it = store.find(name);
    return it->second;
}
