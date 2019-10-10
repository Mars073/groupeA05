#include "GameMap.h"

GameMap::GameMap()
{
    texture.loadFromFile("data/images/simplemap_sprite.png");
    setWidth(64);
}
GameMap::GameMap(int width)
{
    setWidth(width);
}

void GameMap::setWidth(int _width)
{
   width = _width;
   dataset.clear();
   for (int i = 0; i < width*width; i++)
        dataset.push_back(TileInfo(i, 0));
}

bool GameMap::loadFromFile(string path)
{
    int i = 0;
    char32_t c;
    locale loc (locale(), new codecvt_utf8<char32_t>);
    basic_ifstream<char32_t> fdat(path, ios::binary);
    fdat.imbue(loc);
    string header;
    for (int ii = 0; ii < 3 && fdat.get(c); ii++)
        header+=c;
    //cout << "**" << header;
    if (header != "map")
        return false; // no map header

    if (fdat.get(c))
        setWidth(c-48);
    else
        return false; // no size
    cout << ": " << (c-48) << endl;
    dataset.clear();
    while (fdat.get(c))
    {
        if (c == '\n' || c == '\r')
            continue;
        if (i >= width*width)
            break;
        //cout << (i+1) <<"::" << c << endl;
        dataset.push_back(TileInfo(i++, c-48));
    }
    cout << "sz: " << dataset.size() << endl;
    return true;
}

Vector2u GameMap::tx2loc(int TextureID) const
{
    if (--TextureID < 0)
        return Vector2u(texture.getSize().x, texture.getSize().y);//vide
    return Vector2u(
        (TextureID%TEXTURE_RANGE)*2*TILE_SIZE +16,
        (TextureID/TEXTURE_RANGE)*3*TILE_SIZE +48
    );
}

vector<TileInfo> GameMap::getNeighboursInfo(const int index) const
{
    vector<TileInfo> tmp;
    /*N*/tmp.push_back(dataset.at(index < width ? index : index - width));
    /*E*/tmp.push_back(dataset.at((index + 1)%width == 0 ? index : index + 1));
    /*S*/tmp.push_back(dataset.at(index+width >= dataset.size() ? index : index + width));
    /*O*/tmp.push_back(dataset.at((index + 1) % width == 1 || index == 0 ? index : index - 1));
    return tmp;
}

void GameMap::draw() const
{
    Game *g = Game::getInstance();

    //dataset.size();
    for (unsigned int i = 0; i < dataset.size(); i++)
    {
        TileInfo tile = dataset[i];
        Vector2u pos(tile.getPosition(width));
        Vector2u posTX(tx2loc(tile.FLOOR_ID));
        pos.x*=TILE_SIZE;
        pos.y*=TILE_SIZE;
        g->drawImage(texture, posTX.x, posTX.y, TILE_SIZE, TILE_SIZE, pos.x, pos.y);
        try
        {

            vector<TileInfo> nears = getNeighboursInfo(i);
            //borders
            if (nears.at(0).FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x, posTX.y-TILE_SIZE/2, TILE_SIZE, TILE_SIZE/2, pos.x, pos.y);
            }
            if (nears.at(1).FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+TILE_SIZE, posTX.y, TILE_SIZE/2, TILE_SIZE, pos.x+TILE_SIZE/2, pos.y);
            }
            if (nears.at(2).FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x, posTX.y+TILE_SIZE, TILE_SIZE, TILE_SIZE/2, pos.x, pos.y+TILE_SIZE/2);
            }
            if (nears.at(3).FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x-TILE_SIZE/2, posTX.y, TILE_SIZE/2, TILE_SIZE, pos.x, pos.y);
            }
            // inner corners

        }
        catch (int e)
        {
            //
        }
    }
}
