#include "Game.h"
#include "GameMap.h"
#include<iostream>

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
    sprite.setTextureRect(IntRect(0, 0, 32, 32));

    for (int i = 0; i < 64; i++)
    {
        sprite.setPosition(i % width)*32.f, i/width*32.f);
        Game::window->draw(sprite);
    }
    std::cout << "render";
}


void GameMap::setTexture(Texture texture)
{
    this->texture = texture;
}
