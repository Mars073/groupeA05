#include "Util/ResourcesLoader.h"

ResourcesLoader::ResourcesLoader()
{
    clock.restart();
}

ResourcesLoader::~ResourcesLoader()
{
    //dtor
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
        thread(&ResourcesLoader::task, this).detach();
}
void ResourcesLoader::task()
{
    status = Status::LOADING;
    //this_thread::sleep_for(chrono::milliseconds(200));
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
            error_message =  "font::"+font[0];
            return;
        }
        loaded++;
    }
    for (string* sound: sounds)
    {
        string filename = reader.Get("sounds", sound[0], sound[1]);
        if (!sm->load(sound[0], filename))
        {
            std::cout << "::" << sound[1] << std::endl;
            status = Status::ERROR;
            error_message = "sound::"+sound[0];
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
            error_message = "image::"+image[0];
            return;
        }
        loaded++;
    }
    //loaded = clock.getElapsedTime().asMilliseconds();
    finish_at = clock.getElapsedTime().asMilliseconds();
    status = Status::LOADED;
    //this_thread::sleep_for(chrono::seconds(2));
    //setScene(new ConcreteStrategyHomeScene);
}
