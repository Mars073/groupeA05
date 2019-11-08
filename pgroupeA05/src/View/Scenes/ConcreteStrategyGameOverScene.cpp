#include "View/Scenes/ConcreteStrategyGameOverScene.h"

ConcreteStrategyGameOverScene::ConcreteStrategyGameOverScene()
{
    //ctor
}

ConcreteStrategyGameOverScene::~ConcreteStrategyGameOverScene()
{
    //dtor
}


void ConcreteStrategyGameOverScene::draw(RenderTarget& target, RenderStates states) const
{
    Text text("GAME OVER", *fm->get("morpheus"), 64);
    text.setFillColor(sf::Color::Red);
    text.setPosition(
            SingletonGame::W_WIDTH/2-text.getLocalBounds().width/2,
            SingletonGame::W_HEIGHT/2-text.getLocalBounds().height/2
    );
    target.draw(text, states);
}
void ConcreteStrategyGameOverScene::eventHandler(Event)
{

}
