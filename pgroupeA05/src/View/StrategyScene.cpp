#include "View/StrategyScene.h"
#include "Model/SingletonGame.h"

StrategyScene::StrategyScene() {}

StrategyScene::~StrategyScene() {}

RenderWindow* StrategyScene::getWindow()
{
    Game* g = Game::getInstance();
    return g->getWindow();
}

void StrategyScene::setScene(StrategyScene* _scene)
{
    Game* g = Game::getInstance();
    g->setScene(_scene);
}

void StrategyScene::gotoPreviousScene()
{
    Game* g = Game::getInstance();
    g->gotoPreviousScene();
}
