#include "Game.h"

int main()
{
    Game* game = Game::getInstance();
    while (game->isOpen())
    {
        game->pollEvent();
        game->draw();
    }
    return 0;
}
