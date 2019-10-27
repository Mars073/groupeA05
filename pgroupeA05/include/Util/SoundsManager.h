#ifndef SOUNDSMANAGER_H
#define SOUNDSMANAGER_H

#include <Util/RessourcesManager.h>
#include <SFML/Audio.hpp>

using sf::Sound;
using sf::SoundBuffer;

class SoundsManager:public RessourcesManager<Sound>
{
    private:
        SoundsManager();
        static map<string, Sound*> store;
        static map<string, SoundBuffer*> buffers;
    public:
        SoundsManager(const SoundsManager&) = delete;
        SoundsManager(SoundsManager&&) = delete;
        SoundsManager& operator = (const SoundsManager&) = delete;
        SoundsManager& operator = (SoundsManager&&) = delete;
        static SoundsManager* getInstance();
        virtual ~SoundsManager();
        bool load(string, string) override;
        Sound* get(string) const override;
        Sound* operator[](string name) const {return get(name);}
        void play(string) const;
        void pause(string) const;
        void stop(string) const;
        void stopAll() const;

};

#endif // SOUNDSMANAGER_H
