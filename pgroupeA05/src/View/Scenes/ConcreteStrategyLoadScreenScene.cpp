#include "View/Scenes/ConcreteStrategyLoadScreenScene.h"

ConcreteStrategyLoadScreenScene::ConcreteStrategyLoadScreenScene()
{
    if (!logo.loadFromFile("data/images/helha.png"))
    {
        return;
    }
    error = "";
    clock.restart();
    thread(&ConcreteStrategyLoadScreenScene::load_resources, this).detach();
}

void ConcreteStrategyLoadScreenScene::draw(RenderTarget& target, RenderStates states) const
{
    target.clear(Color::White);
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "FAIL" << std::endl;
        return;
    }
    Text text;
    text.setFont(font);
    text.setString(error);
    text.setCharacterSize(24);
    text.setPosition(40, 40);
    text.setFillColor(Color::Red);

    target.draw(text);

    if (loaded >= MAX_LOAD)
    {
        int now = clock.getElapsedTime().asMilliseconds();
        int delta_anim = now-loaded;
        Sprite logo_anim;
        logo_anim.setTexture(logo);
        logo_anim.setPosition(200, 280-112.f*(min(1000, delta_anim)/1000.f));
        target.draw(logo_anim);
    }

    RectangleShape mask(Vector2f(640, 200));
    mask.setPosition(0, 300);
    mask.setFillColor(Color::White);
    target.draw(mask);


    RectangleShape bar(Vector2f(600.f*((float)min(MAX_LOAD, loaded)/MAX_LOAD), 24));
    bar.setPosition(320.f-300.f*((float)min(MAX_LOAD, loaded)/MAX_LOAD), 280);
    bar.setFillColor(Color(0, 152, 147));
    target.draw(bar);
}

void ConcreteStrategyLoadScreenScene::eventHandler(Event event)
{
    //
}

void ConcreteStrategyLoadScreenScene::load_resources()
{
    this_thread::sleep_for(chrono::milliseconds(200));
    INIReader reader("data/data.ini");
    if (reader.ParseError() < 0)
    {
        error = "No ini file";
        return;
    }
    for (string* font: fonts)
    {
        string filename = reader.Get("fonts", font[0], font[1]);
        if (!fm->load(font[0], filename))
        {
            error = "font::"+font[0];
            return;
        }
        loaded++;
    }
    for (string* sound: sounds)
    {
        string filename = reader.Get("sounds", sound[0], sound[1]);
        if (!sm->load(sound[0], filename))
        {
            std::cout << "::" << sound[1] << std::endl;
            error = "sound::"+sound[0];
            return;
        }
        loaded++;
    }
    for (string* image: images)
    {
        string filename = reader.Get("images", image[0], image[1]);
        if (!tm->load(image[0], filename))
        {
            error = "image::"+image[0];
            return;
        }
        loaded++;
    }
    loaded = clock.getElapsedTime().asMilliseconds();
    this_thread::sleep_for(chrono::seconds(2));
    setScene(new ConcreteStrategyHomeScene);
}
