#include "Scene.h"
#include "Game.h"

Scene::Scene() {}

Scene::~Scene() {}

Texture Scene::getTexture(string name, string path)
{
    map<string, Texture>::iterator it;
    Texture tmp;
    it = textures.find(name);
    if (it != textures.end())
        return it->second;
    if (tmp.loadFromFile(path))
        textures.insert(pair<string, Texture>(name, tmp));
    return tmp;
}

Font Scene::getFont(string name, string path)
{
    map<string, Font>::iterator it;
    Font tmp;
    it = fonts.find(name);
    if (it != fonts.end())
        return it->second;
    if (tmp.loadFromFile(path))
        fonts.insert(pair<string, Font>(name, tmp));
    return tmp;
}

RenderWindow* Scene::getWindow()
{
    Game* g = Game::getInstance();
    return g->getWindow();
}
