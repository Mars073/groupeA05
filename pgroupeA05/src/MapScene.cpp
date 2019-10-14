#include "MapScene.h"

MapScene::MapScene()
{
    // load default map: 0
    gmap.loadFromFile("data/maps/map_0.bin");
}


void MapScene::draw(RenderTarget& target, RenderStates states) const
{
    const Vector2f vw = target.getView().getCenter();
    gmap.draw();
    Font f = Ressources::getFont("arial", "data/fonts/arial.ttf");
    Text text("<ESC> Menu - <A> Interact", f);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::Black);
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
        case Keyboard::O:
            {

                v.setCenter(Vector2f(2080, 3008));
                win->setView(v);
                return;
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
