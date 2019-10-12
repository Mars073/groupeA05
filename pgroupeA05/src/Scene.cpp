#include "Scene.h"
#include "Game.h"

Scene::Scene() {}

Scene::~Scene() {}

RenderWindow* Scene::getWindow()
{
    Game* g = Game::getInstance();
    return g->getWindow();
}

void Scene::setScene(Scene* _scene)
{
    Game* g = Game::getInstance();
    g->setScene(_scene);
}
