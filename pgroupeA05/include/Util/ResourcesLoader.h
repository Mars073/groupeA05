// *** ADDED BY HEADER FIXUP ***
#include <istream>
#include <string>
// *** END ***
#ifndef RESOURCESLOADER_H
#define RESOURCESLOADER_H

#include<iostream>
#include<string>
#include "Util/INIReader.h"
#include "Util/FontsManager.h"
#include "Util/SoundsManager.h"
#include "Util/TexturesManager.h"
#include <SFML/System.hpp>
#include <SFML/System/Thread.hpp>

using std::string;
using sf::Clock;
using sf::Time;
using sf::Thread;

class ResourcesLoader
{
    public:
        const int MAX_LOAD = 16;
        enum class Status {PENDING, LOADING, LOADED, ERROR};
    private:
        FontsManager*   fm = FontsManager::getInstance();
        SoundsManager*  sm = SoundsManager::getInstance();
        TexturesManager*tm = TexturesManager::getInstance();
        Clock clock;
        Thread* _async = nullptr;
        void task();
        int loaded = 0;
        unsigned finish_at = -1;
        Status status = Status::PENDING;
        string error_message = "No error";
        string fonts[2][2] = {
            { "arial", "data/fonts/arial.ttf"},
            { "morpheus", "data/fonts/morpheus.ttf"}
        };
        string images[10][2] = {
            {"icon", "data/images/icon.png"},
            {"title", "data/images/background-title.png"},
            {"fight", "data/images/BackGroudCombat.png"},
            {"status", "data/images/bg_menu_status.jpg"},
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

    public:
        ResourcesLoader();
        virtual ~ResourcesLoader();
        Status getStatus() const;
        string getError() const;
        int getLoaded() const;
        unsigned getTime() const;
        void load_resources();

};

#endif // RESOURCESLOADER_H
