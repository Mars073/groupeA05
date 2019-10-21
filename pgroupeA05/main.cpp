#include "Model/SingletonGame.h"
//#include "FightScene.h"

int main()
{
    //FightScene *fn = new FightScene();
    SingletonGame* game = SingletonGame::getInstance();
    //game->setScene(fn);
    while (game->isOpen())
    {
        game->pollEvent();
        game->draw();
    }
    return 0;
}
