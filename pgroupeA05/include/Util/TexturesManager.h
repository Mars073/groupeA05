#ifndef TEXTURESMANAGER_H
#define TEXTURESMANAGER_H

#include <Util/ResourcesManager.h>
#include <SFML/Graphics.hpp>

using sf::Texture;

class TexturesManager:public ResourcesManager<Texture>
{
    private:
        TexturesManager();
        static map<string, Texture*> store;
    public:
        TexturesManager(const TexturesManager&) = delete;
        TexturesManager(TexturesManager&&) = delete;
        TexturesManager& operator = (const TexturesManager&) = delete;
        TexturesManager& operator = (TexturesManager&&) = delete;
        static TexturesManager* getInstance();
        virtual ~TexturesManager();
        bool load(string, string) override;
        Texture* get(string) const override;
};

#endif // TEXTURESMANAGER_H
