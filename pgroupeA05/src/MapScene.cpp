#include "MapScene.h"

MapScene::MapScene():player("Hero", 100, 40, 50, 40, 60)
{
    // load default map: 0
    gmap.loadFromFile("data/maps/map_0.bin");
    // default position for map 0
    player.setPosition(65., 94.);
}
void MapScene::setCamera(RenderTarget& target, float cx, float cy) const
{
    setCamera(target, Vector2f(cx, cy));
}
void MapScene::setCamera(RenderTarget& target, Vector2f center) const
{
    View view = target.getView();
    center.x = min(gmap.getWidth()*gmap.TILE_SIZE-Game::W_WIDTH/2.f, max(Game::W_WIDTH/2.f, center.x));
    center.y = min(gmap.getWidth()*gmap.TILE_SIZE-Game::W_HEIGHT/2.f, max(Game::W_HEIGHT/2.f, center.y));
    view.setCenter(center);
    target.setView(view);
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

    Vector2f player_position = player.getPosition();
    setCamera(target, player_position.x*gmap.TILE_SIZE, player_position.y*gmap.TILE_SIZE);

    TileInfo gob = gmap.xy2t(player_position);
    if (gob.TOPMOST && gob.GAMEOBJECT_ID > 0)
    {
        Vector2u posOB(gmap.ob2loc(gob.GAMEOBJECT_ID));
        Texture texture(Resources::getTexture("simplemap", "data/images/simplemap_sprite.png"));
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(posOB.x, posOB.y, gmap.TILE_SIZE, gmap.TILE_SIZE));
        sprite.setPosition(floor(player_position.x)*32., floor(player_position.y)*32.);
        sprite.setColor(sf::Color(255, 255, 255, 128));
        target.draw(sprite);
    }

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
        Vector2f movement(.0f, .0f);
        switch (event.key.code)
        {
        case Keyboard::Z:
        case Keyboard::Up:
        {
            player.setOrientation(0);
            movement = Vector2f(.0, -1.);
            break;
        }
        case Keyboard::Down:
        {
            player.setOrientation(2);
            movement = Vector2f(.0, 1.);
            break;
        }
        case Keyboard::Left:
        {
            player.setOrientation(3);
            movement = Vector2f(-1., .0);
            break;
        }
        case Keyboard::Right:
        {
            player.setOrientation(1);
            movement = Vector2f(1., .0);
            break;
        }
        case Keyboard::Escape:
            {
                setScene(new MenuScene);
                return;
            }
        default: break;
        }
        if (!gmap.xy2t(player.getPosition()+movement).COLLISION)
            player.move(movement);
    }
}
