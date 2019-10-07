#include "GameMap.h"

GameMap::GameMap()
{
    setWidth(64);
}
GameMap::GameMap(int width)
{
    setWidth(width);
}

void GameMap::setWidth(int _width)
{
   width = _width;
   dataset = vector<int>(width*width, 0);
}

bool GameMap::loadFromFile(string path)
{
    locale loc (locale(), new codecvt_utf8<char32_t>);
    basic_ifstream<char32_t> fdat(path, ios::binary);
    fdat.imbue(loc);

    int i = 0;
    char32_t c;
    if (fdat.get(c) != 'm' || fdat.get(c) != 'a' || fdat.get(c) != 'p')
        return false; // no map header
    if (fdat.get(c))
        setWidth(c-48);
    else
        return false;
    while (fdat.get(c))
    {
        if (c == '\n' || c == '\r')
            continue;
        if (i >= width*width)
            break;
        cout << (i+1) <<"::" << c << endl;
        dataset[i++] = c-48;
    }
    return true;
}
