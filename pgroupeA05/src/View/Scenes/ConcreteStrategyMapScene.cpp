#include "View/Scenes/ConcreteStrategyMapScene.h"

ConcreteStrategyMapScene::ConcreteStrategyMapScene():player("Hero", 100, 40, 50, 40, 60)
{
    // load default map: 0
    gmap.loadFromFile("data/maps/world_0.bin");
    // default position for map 0
    player.setPosition(65., 94.);
}
void ConcreteStrategyMapScene::setCamera(RenderTarget& target, float cx, float cy) const
{
    setCamera(target, Vector2f(cx, cy));
}
void ConcreteStrategyMapScene::setCamera(RenderTarget& target, Vector2f center) const
{
    View view = target.getView();
    center.x = min(gmap.getWidth()*gmap.TILE_SIZE-SingletonGame::W_WIDTH/2.f, max(SingletonGame::W_WIDTH/2.f, center.x));
    center.y = min(gmap.getWidth()*gmap.TILE_SIZE-SingletonGame::W_HEIGHT/2.f, max(SingletonGame::W_HEIGHT/2.f, center.y));
    view.setCenter(center);
    target.setView(view);
}

void ConcreteStrategyMapScene::playFXIntro()
{
    fxClock.restart();
    controller = false;
    isFXIntro = true;
    thread(&ConcreteStrategyMapScene::timeoutFXIntro, this).detach();
}
void ConcreteStrategyMapScene::timeoutFXIntro()
{
    this_thread::sleep_for(chrono::seconds(20));
    controller = true;
    isFXIntro = false;
}

void ConcreteStrategyMapScene::drawFXIntro(RenderTarget& target) const
{
    Time now = fxClock.getElapsedTime();

    View view = target.getView();
    Vector2f center(2080, 3408.0-min(400., now.asMilliseconds()/50.));
    view.setCenter(center);
    target.setView(view);

    RectangleShape rect(Vector2f(SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT));
    rect.setPosition(Vector2f(center.x-SingletonGame::W_WIDTH/2, center.y-SingletonGame::W_HEIGHT/2));
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
        text.setPosition(Vector2f(center.x-SingletonGame::W_WIDTH/2+16, center.y-SingletonGame::W_HEIGHT/2+64+i*32));
        target.draw(text);
    }
}

void ConcreteStrategyMapScene::draw(RenderTarget& target, RenderStates states) const
{
    gmap.draw();
    target.draw(player);
    if (isFXIntro)
        return drawFXIntro(target);

    Vector2f player_position = player.getPosition();
    setCamera(target, player_position.x*gmap.TILE_SIZE, player_position.y*gmap.TILE_SIZE);

    try {
        TileInfo gob = gmap.xy2t(player.getAbsolutePosition());
        if (gob.TOPMOST && gob.GAMEOBJECT_ID > 0)
        {
            Vector2u posOB(gmap.ob2loc(gob.GAMEOBJECT_ID));
            Texture texture(Resources::getTexture("simplemap", "data/images/simplemap_sprite.png"));
            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(posOB.x, posOB.y, gmap.TILE_SIZE, gmap.TILE_SIZE));
            sprite.setPosition(player.getRelativePosition());
            sprite.setColor(sf::Color(255, 255, 255, 128));
            target.draw(sprite);
        }
    }
    catch (const out_of_range& oor) { }
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

void ConcreteStrategyMapScene::eventHandler(Event event) {
    if (event.type == Event::KeyPressed)
    {
        Vector2f movement(.0f, .0f);
        switch (event.key.code)
        {
            case Keyboard::A:
            case Keyboard::Enter:
            {
                GameMap::neighboursInfo nears = gmap.getNeighboursInfo(gmap.xy2i(player.getRelativePosition()));
                switch (player.getOrientation())
                {
                    case 1: // EST
                    {
                        gmap.interact(player, nears.E, gmap);
                        break;
                    }
                    case 2: // SOUTH
                    {
                        gmap.interact(player, nears.S, gmap);
                        break;
                    }
                    case 3: // WEST
                    {
                        gmap.interact(player, nears.O, gmap);
                        break;
                    }
                    default: // NORTH = 0
                    {
                        gmap.interact(player, nears.N, gmap);
                        break;
                    }
                }
                break;
            }
            case Keyboard::Z:
            case Keyboard::Up:
            {
                player.setOrientation(0);
                movement = Vector2f(.0, -1.);
                break;
            }
            case Keyboard::S:
            case Keyboard::Down:
            {
                player.setOrientation(2);
                movement = Vector2f(.0, 1.);
                break;
            }
            case Keyboard::Q:
            case Keyboard::Left:
            {
                player.setOrientation(3);
                movement = Vector2f(-1., .0);
                break;
            }
            case Keyboard::D:
            case Keyboard::Right:
            {
                player.setOrientation(1);
                movement = Vector2f(1., .0);
                break;
            }
            case Keyboard::Escape:
                {
                    setScene(new ConcreteStrategyMenuScene);
                    return;
                }
            default: break;
        }
        TileInfo tile = gmap.xy2t(player.getAbsolutePosition()+movement);
        if (movement != Vector2f(.0f, .0f) && !tile.COLLISION)
        {
            player.move(movement);
            if (tile.GAMEOBJECT_ID > 0)
                gmap.interact(player, &tile, gmap);
        }
    }
}
