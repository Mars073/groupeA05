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

/**
 * This class is used in the LoadScreen Scene.
 *
 * It's loading all of resources use in the game with the different resources manager.
 * The resources are loaded in a different thread.
 */
class ResourcesLoader
{
    public:
        const int MAX_LOAD = 30; //!< The number of resources
        enum class Status {PENDING, LOADING, LOADED, ERROR}; //!< Internal enum with states of loading
    private:
        FontsManager*   fm = FontsManager::getInstance();   //!< Fonts service
        SoundsManager*  sm = SoundsManager::getInstance();  //!< Sounds service
        TexturesManager*tm = TexturesManager::getInstance();//!< Textures service
        Clock clock;                //!< Clock for timestamp
        Thread* _async = nullptr;   //!< Separed thread
        void task();                //!< routine of loading
        int loaded = 0;             //!< loaded files counter
        unsigned finish_at = -1;    //!< timestamp
        Status status = Status::PENDING;//!< current state of loading
        string error_message = "No error";//!< Error messgage
        string fonts[2][2] = {      //!< List of fonts
            { "arial", "data/fonts/arial.ttf"},
            { "morpheus", "data/fonts/morpheus.ttf"}
        };
        string images[24][2] = {    //!< List of images
            {"icon", "data/images/icon.png"},
            {"title", "data/images/background-title.png"},
            {"fight", "data/images/BackGroudCombat.png"},
            {"status", "data/images/bg_menu_status.jpg"},
            {"character", "data/images/character_sprite.png"},
            {"map", "data/images/simplemap_sprite.png"},
            {"mob_goblin", "data/images/monsters/goblin.png"},
            {"mob_skeleton", "data/images/monsters/skeleton.png"},
            {"mob_wolf", "data/images/monsters/wolf.png"},
            {"mob_boss", "data/images/monsters/boss.png"},
            {"hero", "data/images/monsters/hero.png"},
            {"vfx_ice","data/images/gfx/70.png"},
            {"vfx_hit","data/images/gfx/69.png"},
            {"vfx_water","data/images/gfx/71.png"},
            {"vfx_wind","data/images/gfx/66.png"},
            {"vfx_Fire","data/images/gfx/68.png"},
            {"vfx_Super fire","data/images/gfx/68.png"},
            {"vfx_Super ice","data/images/gfx/70.png"},
            {"vfx_Super water","data/images/gfx/71.png"},
            {"vfx_Super wind","data/images/gfx/66.png"},
            {"vfx_ultima","data/images/gfx/67.png"},
            {"ui_panel","data/images/ui_panel.png"},
            {"ui_bar","data/images/ui_bar.png"},
            {"ui_bar-border","data/images/ui_bar-border.png"}
        };
        string sounds[4][2] = {     //!< List of sounds
            {"title", "data/sounds/title.ogg"},
            {"world_0", "data/sounds/world_0.ogg"},
            {"world_1", "data/sounds/world_1.ogg"},
            {"world_2", "data/sounds/world_2.ogg"}
        };

    public:
        ResourcesLoader();          //!< Basic constructor
        virtual ~ResourcesLoader(); //!< Basic destructor
        Status getStatus() const;   //!< Status getter
        string getError() const;    //!< Error message getter
        int getLoaded() const;      //!< Counter getter
        unsigned getTime() const;   //!< timestamp getter
        void load_resources();      //!< method to query loading

};

#endif // RESOURCESLOADER_H
