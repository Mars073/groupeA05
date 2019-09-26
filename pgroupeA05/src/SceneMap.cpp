#include "SceneMap.h"
#include "Graphics.hpp"
#include <iostream>

SceneMap::SceneMap()
{
    sf::Texture texture;
    if (texture.loadFromFile("res/sprite.png"))
        gmap.setTexture(texture);
    else
        std::cout << "Load sprite failled" << std::endl;
}

void SceneMap::draw() {
    //std::cout << "Render" << std::endl;
}

void SceneMap::eventHandler(sf::Event) {
    std::cout << "Event" << std::endl;
}
