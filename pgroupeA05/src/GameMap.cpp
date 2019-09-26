#include "Game.h"
#include "GameMap.h"

GameMap::GameMap()
{
    dataset = new int[64];
}
GameMap::~GameMap()
{
   delete[] dataset;
}

void GameMap::draw()
{
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setInRect(516, 2, 32, 32);

    for (int i = 0; i < 64; i++)
    {
        sprite.setPosition((i % width)*32.f, i/width*32.f);
        Game::window->draw(sprite);
    }
}


void GameMap::setTexture(Texture texture)
{
    this->texture = texture;
}
