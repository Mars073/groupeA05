#include "MapScene.h"

MapScene::MapScene()
{
    // load default map: 0
    gmap.loadFromFile("data/maps/map_0.bin");
}


void MapScene::draw()
{
    RenderWindow* win = getWindow();
    gmap.draw();
    Font f = getFont("arial", "data/fonts/arial.ttf");
    Text text("<ESC> Menu - <A> Interact", f);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    text.setPosition(40, 460);
    win->draw(text);
}

void MapScene::eventHandler(Event event) {}
