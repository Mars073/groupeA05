#include "MapScene.h"

MapScene::MapScene():player("Hero", 100, 40, 50, 40, 60)
{
    // load default map: 0
    gmap.loadFromFile("data/maps/map_0.bin");
    // default position for map 0
    player.setPosition(65., 94.);
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
    rect.setFillColor(Color(0, 0, 0, 120-min(1., max(0., now.asMilliseconds()-18000.)/1500.)*120.));
    target.draw(rect);

    vector<string> story = {
        "Long time ago, there was a beautiful kingdom called Cornelia.",
        "Everyone living there was happy, until the Demon Lord appeared",
        "and unleashed his army upon the kingdom.",
        "Now, there are monsters roaming around everywhere and attacking",
        "anyone in sight.",
        "But as the prophecy foretold, a Hero will appear and defeat the Demon Lord.",
        "Today, after 20 years, the Hero is ready to take on his last journey",
        "to defeat the Demon Lord.",
        "His final quest."
    };
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
    Text text("No text", f);
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
    target.draw(player);
    if (isFXIntro)
        return drawFXIntro(target);
    const Vector2f vw = target.getView().getCenter();
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
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
            //v.move(0, -3);
            player.move(.0, -1.);
            break;
        }
        case Keyboard::Down:
        {
            //v.move(0, 3);
            player.move(.0, 1.);
            break;
        }
        case Keyboard::Left:
        {
            //v.move(-3, 0);
            player.move(-1., .0);
            break;
        }
        case Keyboard::Right:
        {
            //v.move(3, 0);
            player.move(1., .0);
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
