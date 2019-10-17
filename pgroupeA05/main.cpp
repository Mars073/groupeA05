#include "Game.h"
#include "FightScene.h"

int main()
{
    FightScene *fn = new FightScene();
    Game* game = Game::getInstance();
    game->setScene(fn);
    while (game->isOpen())
    {
        game->pollEvent();
        game->draw();
    }
    return 0;
}
