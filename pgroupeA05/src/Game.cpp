#include "Game.h"

Game::Game()
{

}

void Game::setScene(Scene scene) {
    this->scene = scene;
}

Scene Game::getScene() {
    return this->scene;
}
