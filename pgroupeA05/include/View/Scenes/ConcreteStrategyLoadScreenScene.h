#ifndef CONCRETESTRATEGYLOADSCREENSCENE_H
#define CONCRETESTRATEGYLOADSCREENSCENE_H

#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include "View/StrategyScene.h"
#include "View/Scenes/ConcreteStrategyHomeScene.h"
#include "Util/INIReader.h"

using std::thread;
using std::string;

class ConcreteStrategyLoadScreenScene: public StrategyScene
{
    private:
        int loaded = 0;
        const int MAX_LOAD = 15;
        string error;
        string fonts[2][2] = {
            { "arial", "data/fonts/arial.ttf"},
            { "morpheus", "data/fonts/morpheus.ttf"}
        };
        string images[9][2] = {
            {"icon", "data/images/icon.png"},
            {"title", "data/images/background-title.png"},
            {"fight", "data/images/BackGroudCombat.png"},
            {"character", "data/images/character_sprite.png"},
            {"map", "data/images/simplemap_sprite.png"},
            {"mob_goblin", "data/images/monsters/goblin.png"},
            {"mob_skeleton", "data/images/monsters/skeleton.png"},
            {"mob_wolf", "data/images/monsters/wolf.png"},
            {"mob_boss", "data/images/monsters/boss.png"}
        };
        string sounds[4][2] = {
            {"title", "data/sounds/title.ogg"},
            {"world_0", "data/sounds/world_0.ogg"},
            {"world_1", "data/sounds/world_1.ogg"},
            {"world_2", "data/sounds/world_2.ogg"}
        };
        Texture logo;

    public:
        ConcreteStrategyLoadScreenScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event) override;
        void load_resources();

};
#endif // CONCRETESTRATEGYLOADSCREENSCENE_H
