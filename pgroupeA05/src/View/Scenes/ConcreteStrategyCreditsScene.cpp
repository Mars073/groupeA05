#include "View/Scenes/ConcreteStrategyCreditsScene.h"

ConcreteStrategyCreditsScene::ConcreteStrategyCreditsScene()
{
    clock.restart();
}

ConcreteStrategyCreditsScene::~ConcreteStrategyCreditsScene()
{
    //dtor
}

void ConcreteStrategyCreditsScene::draw(RenderTarget& target, RenderStates states) const
{
    Texture t = *tm->get("status");
    Sprite sprite;
    sprite.setTexture(t);
    target.draw(sprite, states);
}
void ConcreteStrategyCreditsScene::eventHandler(Event event)
{

}
