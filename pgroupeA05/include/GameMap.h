#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include <locale>
#include <string>
#include <codecvt>
#include <fstream>
#include <vector>

using namespace std;

class GameMap
{
    private:
        int width;
        std::vector<int> dataset;
    public:
        GameMap();
        GameMap(int);
        bool loadFromFile(std::string);
        void setWidth(int width);
};

#endif // GAMEMAP_H
