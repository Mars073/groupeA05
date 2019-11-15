#include "Util/ResourcesLoader.h"

ResourcesLoader::ResourcesLoader()
{
    _async = new Thread(&ResourcesLoader::task, this);
    clock.restart();
}

ResourcesLoader::~ResourcesLoader()
{
    if (_async)
    {
        _async->terminate();
        delete _async;
    }
}
ResourcesLoader::Status ResourcesLoader::getStatus() const
{
    return status;
}
string ResourcesLoader::getError() const
{
    return error_message;
}
int ResourcesLoader::getLoaded() const
{
    return loaded;
}
unsigned ResourcesLoader::getTime() const
{
    return finish_at;
}
void ResourcesLoader::load_resources() {
    if (status == Status::PENDING)
    {
        _async->launch();
    }
}
void ResourcesLoader::task()
{
    status = Status::LOADING;

    INIReader reader("data/data.ini");
    if (reader.ParseError() < 0)
    {
        status = Status::ERROR;
        error_message = "No INI file";
        return;
    }
    for (string* font: fonts)
    {
        string filename = reader.Get("fonts", font[0], font[1]);
        if (!fm->load(font[0], filename))
        {
            status = Status::ERROR;
            error_message =  "File not found: font::"+font[0];
            return;
        }
        loaded++;
    }
    for (string* sound: sounds)
    {
        string filename = reader.Get("sounds", sound[0], sound[1]);
        if (!sm->load(sound[0], filename))
        {
            status = Status::ERROR;
            error_message = "File not found: sound::"+sound[0];
            return;
        }
        loaded++;
    }
    for (string* image: images)
    {
        string filename = reader.Get("images", image[0], image[1]);
        if (!tm->load(image[0], filename))
        {
            status = Status::ERROR;
            error_message = "File not found: image::"+image[0];
            return;
        }
        loaded++;
    }
    finish_at = clock.getElapsedTime().asMilliseconds();
    status = Status::LOADED;
    return;
}
