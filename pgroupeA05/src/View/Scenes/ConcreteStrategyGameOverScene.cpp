#include "View/Scenes/ConcreteStrategyGameoverScene.h"

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
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
    Text text("GAME OVER", f);
    text.setCharacterSize(64);
    text.setFillColor(sf::Color::Red);
    text.setPosition(80, 220);
    target.draw(text, states);
}
void ConcreteStrategyGameOverScene::eventHandler(Event)
{

}
