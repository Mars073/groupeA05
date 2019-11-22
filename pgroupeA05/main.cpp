#include "Model/SingletonGame.h"

int main()
{
    SingletonGame* game = SingletonGame::getInstance();

    while (game->isOpen())
    {
        game->draw();
        game->pollEvent();
    }
    return 0;
}
