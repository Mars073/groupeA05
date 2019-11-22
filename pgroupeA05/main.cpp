#include "Model/SingletonGame.h"

int main()
{
    SingletonGame* game = SingletonGame::getInstance();

    while (game->isOpen())
    {
        game->pollEvent();
        game->draw();
    }
    return 0;
}
