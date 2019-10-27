#ifndef FONTSMANAGER_H
#define FONTSMANAGER_H

#include <Util/RessourcesManager.h>
#include <SFML/Graphics.hpp>

using sf::Font;

class FontsManager:RessourcesManager<Font>
{
    private:
        FontsManager();
        static map<string, Font*> store;
    public:
        FontsManager(const FontsManager&) = delete;
        FontsManager(FontsManager&&) = delete;
        FontsManager& operator = (const FontsManager&) = delete;
        FontsManager& operator = (FontsManager&&) = delete;
        static FontsManager* getInstance();
        virtual ~FontsManager();
        bool load(string, string) override;
        Font* get(string) const override;

};

#endif // FONTSMANAGER_H
