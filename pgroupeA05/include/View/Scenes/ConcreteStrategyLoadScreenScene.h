#ifndef CONCRETESTRATEGYLOADSCREENSCENE_H
#define CONCRETESTRATEGYLOADSCREENSCENE_H

#include<iostream>
#include<string>
#include "View/StrategyScene.h"
#include "View/Scenes/ConcreteStrategyHomeScene.h"
#include "Util/ResourcesLoader.h"

using std::string;

class ConcreteStrategyLoadScreenScene: public StrategyScene
{
    private:
        Texture logo;
        ResourcesLoader loader;

    public:
        ConcreteStrategyLoadScreenScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event) override;
        void load_resources();

};
#endif // CONCRETESTRATEGYLOADSCREENSCENE_H
