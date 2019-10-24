#include "Model/SingletonGame.h"

SingletonGame* SingletonGame::getInstance()
{
    static SingletonGame instance;
    return &instance;
}

SingletonGame::SingletonGame()
{
    window = new RenderWindow(sf::VideoMode(W_WIDTH, W_HEIGHT), "Final Quest", Style::Titlebar | Style::Close);
    window->setMouseCursorVisible(false);
    window->setFramerateLimit(60);
    Image icon;
    if (icon.loadFromFile("data/images/icon.png"))
    {
        Vector2u sz = icon.getSize();
        window->setIcon(sz.x, sz.y, icon.getPixelsPtr());
    }
    resetView();
}

SingletonGame::~SingletonGame()
{
    delete scene;
    delete window;
}

Player* SingletonGame::getPlayerPTR() const
{
    return player;
}

void SingletonGame::draw() const
{
    window->clear();
    window->draw(*scene);
    window->display();
}

void SingletonGame::drawImage(const Texture& image, int sx, int sy, int sw, int sh, int dx, int dy) const
{
    return drawImage(image, sx, sy, sw, sh, dx, dy, sw, sh);
}

void SingletonGame::drawImage(const Texture& image, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh) const
{
    Sprite sprite;
    sprite.setTexture(image);
    sprite.setTextureRect(IntRect(sx, sy, sw, sh));
    sprite.setPosition(dx, dy);
    if (sw != dw || sh != dh)
        sprite.setScale((float)sw / dw, (float)sh / dh);
    window->draw(sprite);
}

RenderWindow* SingletonGame::getWindow() const
{
    return window;
}

void SingletonGame::setScene(StrategyScene* _scene)
{
    delete previous_scene;
    previous_scene = scene;
    scene = _scene;
    resetView();
}

void SingletonGame::gotoPreviousScene()
{
    StrategyScene* tmp;
    tmp = scene;
    scene = previous_scene;
    previous_scene = tmp;
    resetView();
}

StrategyScene* SingletonGame::getScene() const
{
    return scene;
}

void SingletonGame::resetView()
{
    window->clear();
    View view = View(FloatRect(0, 0, W_WIDTH, W_HEIGHT));
    view.setCenter(W_WIDTH/2, W_HEIGHT/2);
    window->setView(view);
    window->display();
}

bool SingletonGame::isOpen() const
{
    return window->isOpen();
}

bool SingletonGame::pollEvent(Event& event) const
{
    return window->pollEvent(event);
}

void SingletonGame::pollEvent() const
{
    Event event;
    if (pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            close();
        else if (scene->controller)
            scene->eventHandler(event);
    }
}

void SingletonGame::close() const
{
    window->close();
}

void SingletonGame::test_com() const
{
    window->setTitle("Communication: OK");
}
