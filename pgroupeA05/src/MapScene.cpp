#include "MapScene.h"

MapScene::MapScene()
{
    // load default map: 0
    gmap.loadFromFile("data/maps/map_0.bin");
}

void MapScene::playFXIntro()
{
    fxClock.restart();
    controller = false;
    isFXIntro = true;
    thread(&MapScene::timeoutFXIntro, this).detach();
}
void MapScene::timeoutFXIntro()
{
    this_thread::sleep_for(chrono::seconds(20));
    controller = true;
    isFXIntro = false;
}

void MapScene::drawFXIntro(RenderTarget& target) const
{
    Time now = fxClock.getElapsedTime();

    View view = target.getView();
    Vector2f center(2080, 3408.0-min(400., now.asMilliseconds()/50.));
    view.setCenter(center);
    target.setView(view);

    RectangleShape rect(Vector2f(Game::W_WIDTH, Game::W_HEIGHT));
    rect.setPosition(Vector2f(center.x-Game::W_WIDTH/2, center.y-Game::W_HEIGHT/2));
    rect.setFillColor(Color(0, 0, 0, 180-min(1., max(0., now.asMilliseconds()-18000.)/1500.)*180.));
    target.draw(rect);

    vector<string> story = {
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit.",
        "Pellentesque vel felis a ipsum porttitor maximus. Aliquam erat diam,",
        "rhoncus nec sodales eu, scelerisque ut nunc. Curabitur fermentum egestas nulla,",
        "quis viverra orci eleifend nec. Sed lobortis turpis erat, eu rutrum ligula blandit ut.",
        "Etiam nec lorem non neque sollicitudin faucibus nec non enim. Cras non lorem euismod,",
        "suscipit sem at, auctor elit. Nulla diam lacus, placerat quis dui non,",
        "aliquam blandit enim. Morbi id mauris tristique, vulputate risus porta, maximus magna.",
        "Fusce in mi sit amet sapien facilisis faucibus eget eu nibh.",
        "Fusce in est sit amet nulla efficitur pellentesque."
    };
    Font f = Ressources::getFont("arial", "data/fonts/arial.ttf");
    Text text("", f);
    text.setCharacterSize(16);
    text.setFillColor(Color(255, 255, 255, 255-min(1., max(0., now.asMilliseconds()-18000.)/1500.)*255.));
    for (unsigned i = 0; i < story.size(); i++)
    {
        text.setString(story.at(i));
        text.setPosition(Vector2f(center.x-Game::W_WIDTH/2+16, center.y-Game::W_HEIGHT/2+64+i*32));
        target.draw(text);
    }
}

void MapScene::draw(RenderTarget& target, RenderStates states) const
{
    gmap.draw();
    if (isFXIntro)
        return drawFXIntro(target);
    const Vector2f vw = target.getView().getCenter();
    Font f = Ressources::getFont("arial", "data/fonts/arial.ttf");
    Text text("<ESC> Menu - <A> Interact", f);
    text.setCharacterSize(12);
    text.setFillColor(Color::Black);
    text.setPosition(vw.x-299, vw.y+221);
    target.draw(text);
    text.setFillColor(sf::Color::White);
    text.setPosition(vw.x-300, vw.y+220);
    target.draw(text);
}

void MapScene::eventHandler(Event event) {
    if (event.type == Event::KeyPressed)
    {
        RenderWindow* win = getWindow();
        View v = win->getView();
        switch (event.key.code)
        {
        case Keyboard::Up:
        {
            v.move(0, -3);
            break;
        }
        case Keyboard::Down:
        {
            v.move(0, 3);
            break;
        }
        case Keyboard::Left:
        {
            v.move(-3, 0);
            break;
        }
        case Keyboard::Right:
        {
            v.move(3, 0);
            break;
        }
        case Keyboard::Escape:
            {
                setScene(new HomeScene);
                break;
            }
        default: break;
        }
        Vector2f ct = v.getCenter();
        if (ct.x >= Game::W_WIDTH/2 && ct.x <= gmap.getWidth()*gmap.TILE_SIZE-Game::W_WIDTH/2 &&
            ct.y >= Game::W_HEIGHT/2 && ct.y <= gmap.getWidth()*gmap.TILE_SIZE-Game::W_HEIGHT/2)
            win->setView(v);
    }
}
