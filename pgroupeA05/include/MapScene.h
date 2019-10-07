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
        vector<int> dataset;
    public:
        GameMap();
        GameMap(int);
        bool loadFromFile(string);
        void setWidth(int width);
};

#endif // GAMEMAP_H
