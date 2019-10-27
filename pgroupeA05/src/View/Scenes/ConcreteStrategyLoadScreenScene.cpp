#include "View/Scenes/ConcreteStrategyLoadScreenScene.h"

ConcreteStrategyLoadScreenScene::ConcreteStrategyLoadScreenScene()
{
    error = "";
    thread(&ConcreteStrategyLoadScreenScene::load_resources, this).detach();
}

void ConcreteStrategyLoadScreenScene::draw(RenderTarget& target, RenderStates states) const
{
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
}

void ConcreteStrategyLoadScreenScene::eventHandler(Event event)
{
    //
}

void ConcreteStrategyLoadScreenScene::load_resources()
{
    this_thread::sleep_for(chrono::milliseconds(200));
    FontsManager* fm = FontsManager::getInstance();
    SoundsManager* sm = SoundsManager::getInstance();
    TexturesManager* tm = TexturesManager::getInstance();
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
    }
    for (string* image: images)
    {
        string filename = reader.Get("images", image[0], image[1]);
        if (!tm->load(image[0], filename))
        {
            error = "image::"+image[0];
            return;
        }
    }
    error = "OK";
    this_thread::sleep_for(chrono::seconds(1));
    setScene(new ConcreteStrategyHomeScene);
}
