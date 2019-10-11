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
    delete scene;
    delete window;
}

void Game::draw() const
{
    window->clear();
    scene->draw();
    window->display();
}

void Game::drawImage(const Texture& image, int sx, int sy, int sw, int sh, int dx, int dy) const
{
    return drawImage(image, sx, sy, sw, sh, dx, dy, sw, sh);
}

void Game::drawImage(const Texture& image, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh) const
{
    Sprite sprite;
    sprite.setTexture(image);
    sprite.setTextureRect(IntRect(sx, sy, sw, sh));
    sprite.setPosition(dx, dy);
    if (sw != dw || sh != dh)
        sprite.setScale((float)sw / dw, (float)sh / dh);
    window->draw(sprite);
}

RenderWindow* Game::getWindow() const
{
    return window;
}

void Game::setScene(Scene* _scene)
{
    if (scene)
        delete scene;
    scene = _scene;
}

Scene* Game::getScene() const
{
    return scene;
}


bool Game::isOpen() const
{
    return window->isOpen();
}

bool Game::pollEvent(Event& event) const
{
    return window->pollEvent(event);
}

void Game::pollEvent() const
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

void Game::close() const
{
    window->close();
}

void Game::test_com() const
{
    window->setTitle("Communication: OK");
}
