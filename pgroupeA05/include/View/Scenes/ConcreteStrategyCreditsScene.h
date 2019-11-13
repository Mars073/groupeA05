#ifndef VIEW_SCENES_CONCRETESTRATEGYCREDITSSCENE_H
#define VIEW_SCENES_CONCRETESTRATEGYCREDITSSCENE_H

#include <View/StrategyScene.h>


class ConcreteStrategyCreditsScene : public StrategyScene
{
    private:
    public:
        ConcreteStrategyCreditsScene();
        virtual ~ConcreteStrategyCreditsScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event) override;

};

#endif // VIEW_SCENES_CONCRETESTRATEGYCREDITSSCENE_H
