#include "View/StrategyScene.h"
#include "Model/SingletonGame.h"

StrategyScene::StrategyScene() {}

StrategyScene::~StrategyScene() {}

RenderWindow* StrategyScene::getWindow()
{
    SingletonGame* g = SingletonGame::getInstance();
    return g->getWindow();
}

void StrategyScene::setScene(StrategyScene* _scene) const
{
    SingletonGame* g = SingletonGame::getInstance();
    g->setScene(_scene);
}

void StrategyScene::gotoPreviousScene() const
{
    SingletonGame* g = SingletonGame::getInstance();
    g->gotoPreviousScene();
}
