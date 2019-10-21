#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include <View/StrategyScene.h>
#include <SFML/Graphics.hpp>


class ConcreteStrategyGameOverScene: public StrategyScene
{
    public:
        /** Default constructor */
        ConcreteStrategyGameOverScene();
        /** Default destructor */
        virtual ~ConcreteStrategyGameOverScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // GAMEOVERSCENE_H
