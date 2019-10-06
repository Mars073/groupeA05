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

    char32_t c;
    while (fdat.get(c))
    {
        if (c == '\n' || c == '\r')
            continue;
        cout << "::" << c << endl;
    }
    return true;
}