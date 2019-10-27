#include "Util/SoundsManager.h"

map<string, Sound*> SoundsManager::store;
map<string, SoundBuffer*> SoundsManager::buffers;

SoundsManager::SoundsManager()
{
}

SoundsManager::~SoundsManager()
{
    map<string, Sound*>::iterator it;
    for (it = store.begin(); it != store.end(); it++)
    {
        delete it->second;
    }
    map<string, SoundBuffer*>::iterator itb;
    for (itb = buffers.begin(); itb != buffers.end(); itb++)
    {
        delete itb->second;
    }
}

SoundsManager* SoundsManager::getInstance()
{
    static SoundsManager instance;
    return &instance;
}

bool SoundsManager::load(string name, string filename)
{
    SoundBuffer buffer;
    Sound sound;
    if (!buffer.loadFromFile(filename))
        return false;
    sound.setBuffer(buffer);
    buffers[name] = new SoundBuffer(buffer);
    store[name] = new Sound(sound);
    return true;
}

Sound* SoundsManager::get(string name) const
{
    map<string, Sound*>::iterator it;
    it = store.find(name);
    return it->second;
}

void SoundsManager::play(string name) const
{
    map<string, Sound*>::iterator it;
    it = store.find(name);
    if (it != store.end())
        it->second->play();
}
void SoundsManager::pause(string name) const
{
    map<string, Sound*>::iterator it;
    it = store.find(name);
    if (it != store.end())
        it->second->play();
}
void SoundsManager::stop(string name) const
{
    map<string, Sound*>::iterator it;
    it = store.find(name);
    if (it != store.end())
        it->second->play();
}
void SoundsManager::stopAll() const
{
    map<string, Sound*>::iterator it;
    for (it = store.begin(); it != store.end(); it++)
        it->second->stop();
}
