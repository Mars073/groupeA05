#include "View/Scenes/ConcreteStrategyLoadScreenScene.h"

ConcreteStrategyLoadScreenScene::ConcreteStrategyLoadScreenScene()
{
    if (!logo.loadFromFile("data/images/helha.png"))
    {
        error = "No logo";
        return;
    }
    error = "";
    loader.load_resources();
    clock.restart();
}

void ConcreteStrategyLoadScreenScene::draw(RenderTarget& target, RenderStates states) const
{
    target.clear(Color::White);
    Font font;
    if (!font.loadFromFile("data/fonts/arial.ttf"))
    {
        std::cout << "No font" << std::endl;
        return;
    }
    Text text;
    text.setFont(font);
    text.setString(error);
    text.setCharacterSize(24);
    text.setPosition(40, 40);
    text.setFillColor(Color::Red);

    target.draw(text);

    if (loader.getStatus() == loader.Status::LOADED)
    {
        int now = clock.getElapsedTime().asMilliseconds();
        int delta_anim = now-loader.getTime();
        Sprite logo_anim;
        logo_anim.setTexture(logo);
        logo_anim.setPosition(200, 280-112.f*(min(1000, delta_anim)/1000.f));
        target.draw(logo_anim);

        if (delta_anim > 2000)
            setScene(new ConcreteStrategyHomeScene);
    }

    RectangleShape mask(Vector2f(640, 200));
    mask.setPosition(0, 300);
    mask.setFillColor(Color::White);
    target.draw(mask);


    RectangleShape bar(Vector2f(600.f*((float)min(loader.MAX_LOAD, loader.getLoaded())/loader.MAX_LOAD), 24));
    bar.setPosition(320.f-300.f*((float)min(loader.MAX_LOAD, loader.getLoaded())/loader.MAX_LOAD), 280);
    bar.setFillColor(Color(0, 152, 147));
    target.draw(bar);

    Text prct(std::to_string((int)(min((float)loader.MAX_LOAD, (float)loader.getLoaded())/loader.MAX_LOAD*100.f))+"%", font, 18);
    prct.setPosition(320-prct.getLocalBounds().width/2, 281);
    prct.setFillColor(Color::White);
    target.draw(prct);
}

void ConcreteStrategyLoadScreenScene::eventHandler(Event event)
{
    //
}


