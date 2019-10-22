#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <Model/SingletonGame.h>
#include <View/Scenes/ConcreteStrategyMapScene.h>
#include <FightScene.h>
#include <View/Scenes/ConcreteStrategyGameOverScene.h>


class ConcreteStrategyMenuScene : public StrategyScene
{
    private:
        const unsigned short int MENU_LENGTH = 6;
        const string menu[6] = {"Back", "new Home", "new Map", "new Fight", "new Credits", "new Gameover"};
        short int selected_id = 0;

    public:
        /** Default constructor */
        ConcreteStrategyMenuScene();
        /** Default destructor */
        virtual ~ConcreteStrategyMenuScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // MENUSCENE_H
