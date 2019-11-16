#include "Model/SingletonGame.h"
#define TITLE "Final Quest"
SingletonGame* SingletonGame::getInstance()
{
    static SingletonGame instance;
    return &instance;
}

SingletonGame::SingletonGame()
{
    window = new RenderWindow(sf::VideoMode(W_WIDTH, W_HEIGHT), TITLE, Style::Titlebar | Style::Close);
    window->setMouseCursorVisible(false);
    window->setVerticalSyncEnabled(true);
    window->setFramerateLimit(60);
    load_icon();
    resetView();
}

void SingletonGame::load_icon() const
{
    Image icon;
    if (icon.loadFromFile("data/images/icon.png"))
    {
        Vector2u sz = icon.getSize();
        window->setIcon(sz.x, sz.y, icon.getPixelsPtr());
    }
}

SingletonGame::~SingletonGame()
{
    for (unsigned i = 0; i < previous_scene.size(); i++)
    {
        delete previous_scene.at(i);
    }
    if (scene)
        delete scene;
    if (window)
        delete window;
    if (player)
        delete player;
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
    if (scene)
        previous_scene.push_back(scene);
    scene = _scene;
    resetView();
    //std::cout << string(50, '\n'); // clear console
}

void SingletonGame::gotoPreviousScene()
{
    if (previous_scene.size() == 0)
        return;
    StrategyScene* curr = getScene();
    setScene(previous_scene.at(previous_scene.size()-1));
    previous_scene.erase(previous_scene.begin() + previous_scene.size() - 1);
    std::cout << "Si ça freeze, c'est que la destruction de l'ancienne scène se passe mal." << std::endl;
    delete curr;
    //resetView();
}

StrategyScene* SingletonGame::getScene() const
{
    return scene;
}

void SingletonGame::resetView() const
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
        if (event.type == Event::KeyPressed && event.key.code == Keyboard::F11)
        {
            if (window->getSize() == Vector2u(W_WIDTH, W_HEIGHT))
                window->create(VideoMode::getFullscreenModes()[0], TITLE, Style::Fullscreen);
            else
                window->create(VideoMode(W_WIDTH, W_HEIGHT), TITLE, Style::Titlebar | Style::Close);
            window->setMouseCursorVisible(false);
            window->setVerticalSyncEnabled(true);
            window->setFramerateLimit(60);
            load_icon();
            resetView();
        }
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
