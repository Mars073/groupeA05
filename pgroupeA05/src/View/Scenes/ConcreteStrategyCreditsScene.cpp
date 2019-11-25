#include "View/Scenes/ConcreteStrategyCreditsScene.h"
#include "View/Scenes/ConcreteStrategyHomeScene.h"

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
    Texture tx = *tm->get("status");
    Text tt("", *fm->get("arial"));
    Sprite sprite;
    sprite.setTexture(tx);
    target.draw(sprite, states);
}
void ConcreteStrategyCreditsScene::eventHandler(Event event)
{
    if (event.type == sf::Event::KeyPressed)
        setScene(new ConcreteStrategyHomeScene);
}
