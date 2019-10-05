#include "Game.h"

Game* Game::getInstance()
{
    static Game instance;
    return &instance;
}

Game::Game()
{
    window = new RenderWindow(sf::VideoMode(640, 480), "Final Quest", sf::Style::Titlebar | sf::Style::Close);
    window->setMouseCursorVisible(false);
    window->setFramerateLimit(60);
    Image icon;
    if (icon.loadFromFile("data/images/icon.png"))
    {
        Vector2u sz = icon.getSize();
        window->setIcon(sz.x, sz.y, icon.getPixelsPtr());
    }
    View view(sf::Vector2f(16,16), sf::Vector2f(640, 480));
    view.setCenter(320, 240);
    window->setView(view);
}

Game::~Game()
{
    if (scene)
        delete scene;
    if (window)
        delete window;
}

void Game::draw()
{
    window->clear();
    scene->draw();
    window->display();
}

RenderWindow* Game::getWindow()
{
    return window;
}

void Game::setScene(Scene* _scene)
{
    if (scene)
        delete scene;
    scene = _scene;
}

Scene* Game::getScene()
{
    return scene;
}


bool Game::isOpen()
{
    return window->isOpen();
}

bool Game::pollEvent(Event& event)
{
    return window->pollEvent(event);
}

void Game::pollEvent()
{
    Event event;
    if (pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            close();
        else
            scene->eventHandler(event);
    }
}

void Game::close()
{
    window->close();
}

void Game::test_com()
{
    window->setTitle("Communication: OK");
}
