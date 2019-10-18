#include "GameMap.h"
#define PI 3.141592653589793

GameMap::GameMap()
{
    setTexture(Resources::getTexture("simplemap", "data/images/simplemap_sprite.png"));
    setWidth(64);
}
GameMap::GameMap(int width)
{
    setWidth(width);
}

void GameMap::setTexture(const Texture& _texture)
{
    texture = _texture;
}

Texture GameMap::getTexture() const
{
    return texture;
}

void GameMap::setWidth(int _width)
{
   width = _width;
   dataset.clear();
   for (int i = 0; i < width*width; i++)
        dataset.push_back(TileInfo(i, 0));
}

int GameMap::getWidth() const
{
    return width;
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
    if (header != "map")
        return false; // no map header

    if (fdat.get(c))
        setWidth(c-48);
    else
        return false; // no size
    cout << " size: " << (c-48) << endl;
    dataset.clear();
    while (fdat.get(c))
    {
        if (c == '\n' || c == '\r')
            continue;
        if (i >= width*width)
            break;
        dataset.push_back(TileInfo(i++, c-48));
    }
    cout << "map blocks: " << dataset.size() << endl;
    return true;
}

TileInfo GameMap::xy2t(Vector2f vec) const
{
    return dataset.at((unsigned)(vec.y*width+vec.x));
}

unsigned GameMap::xy2i(Vector2f vec) const
{
    return vec.x/TILE_SIZE + vec.y/TILE_SIZE*width;
}

Vector2u GameMap::tx2loc(int textureID) const
{
    if (--textureID < 0)
        return Vector2u(texture.getSize().x, texture.getSize().y);//vide
    if (textureID < 28)
        return Vector2u(
            (textureID%TEXTURE_RANGE)*2*TILE_SIZE + TILE_SIZE/2,
            (textureID/TEXTURE_RANGE)*3*TILE_SIZE + TILE_SIZE*1.5
        );
    textureID-=28;
    return Vector2u(
        textureID%(TEXTURE_RANGE+3)*TILE_SIZE,
        TILE_SIZE*9+textureID/(TEXTURE_RANGE+3)*TILE_SIZE
    );
}

Vector2u GameMap::ob2loc(int objectID) const
{
    return Vector2u(
        TEXTURE_RANGE*TILE_SIZE*2 + (objectID%16)*TILE_SIZE,
        (objectID/16)*TILE_SIZE
    );
}

GameMap::neighboursInfo GameMap::getNeighboursInfo(const int index) const
{
    neighboursInfo tmp;
    const TileInfo* self = dataset.data() + index;
    tmp.N = dataset.data() + (index < width ? index : index - width);
    tmp.E = dataset.data() + ((index + 1)%width == 0 ? index : index + 1);
    tmp.S = dataset.data() + (index+width >= (int)dataset.size() ? index : index + width);
    tmp.O = dataset.data() + (index % width == 0 ? index : index - 1);

    tmp.NE = tmp.N->INDEX == index || tmp.E->INDEX == index ? self : tmp.N + 1;
    tmp.SE = tmp.S->INDEX == index || tmp.E->INDEX == index ? self : tmp.S + 1;
    tmp.SO = tmp.S->INDEX == index || tmp.O->INDEX == index ? self : tmp.S - 1;
    tmp.NO = tmp.N->INDEX == index || tmp.O->INDEX == index ? self : tmp.N - 1;

    return tmp;
}

void GameMap::draw() const
{
    Time now = clock.getElapsedTime();
    Game *g = Game::getInstance();
    Vector2f vw = g->getWindow()->getView().getCenter() - Vector2f(Game::W_WIDTH/2, Game::W_HEIGHT/2);

    for (unsigned i = xy2i(vw)-width; i < dataset.size(); i++)
    {
        TileInfo tile = dataset.at(i);
        Vector2u pos(tile.getPosition(width));
        Vector2u posTX(tx2loc(tile.FLOOR_ID));
        Vector2u posOB(ob2loc(tile.GAMEOBJECT_ID));

        pos.x*=TILE_SIZE;
        pos.y*=TILE_SIZE;
        // skip hidden tiles
        if (pos.x+TILE_SIZE < vw.x || pos.x > vw.x + Game::W_WIDTH ||
            pos.y+TILE_SIZE < vw.y)
            continue;
        if (pos.y > vw.y + Game::W_HEIGHT)
            break;

        if (tile.FLOOR_ID < 29 && tile.FLOOR_ID%TEXTURE_RANGE == 1)
        {
            posTX.x+=floor(cos(now.asMilliseconds()/(120.*PI))*1.5+1.5)*TILE_SIZE*2;
        }
        try
        {
            const int HALF_SIZE = TILE_SIZE/2;
            neighboursInfo nears = getNeighboursInfo(i);
            // quick tile
            if (tile.FLOOR_ID > 28 || (nears.N->FLOOR_ID != tile.FLOOR_ID && nears.E->FLOOR_ID != tile.FLOOR_ID && nears.S->FLOOR_ID != tile.FLOOR_ID && nears.O->FLOOR_ID != tile.FLOOR_ID))
            {
                // floor
                if (tile.FLOOR_ID > 28)
                    g->drawImage(texture, posTX.x, posTX.y, TILE_SIZE, TILE_SIZE, pos.x, pos.y);
                else
                    g->drawImage(texture, posTX.x-HALF_SIZE, posTX.y-TILE_SIZE*1.5, TILE_SIZE, TILE_SIZE, pos.x, pos.y);
                // Game object
                if (tile.GAMEOBJECT_ID > 0)
                    g->drawImage(texture, posOB.x, posOB.y, TILE_SIZE, TILE_SIZE, pos.x, pos.y);
                continue;
            }
            // floor
            g->drawImage(texture, posTX.x, posTX.y, TILE_SIZE, TILE_SIZE, pos.x, pos.y);
            //borders
            if (nears.N->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x, posTX.y-HALF_SIZE, TILE_SIZE, HALF_SIZE, pos.x, pos.y);
            }
            if (nears.E->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+TILE_SIZE, posTX.y, HALF_SIZE, TILE_SIZE, pos.x+HALF_SIZE, pos.y);
            }
            if (nears.S->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x, posTX.y+TILE_SIZE, TILE_SIZE, HALF_SIZE, pos.x, pos.y+HALF_SIZE);
            }
            if (nears.O->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x-HALF_SIZE, posTX.y, HALF_SIZE, TILE_SIZE, pos.x, pos.y);
            }
            // inner corners
            if (nears.N->FLOOR_ID != tile.FLOOR_ID && nears.E->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+TILE_SIZE, posTX.y-HALF_SIZE, HALF_SIZE, HALF_SIZE, pos.x+HALF_SIZE, pos.y);
            }
            if (nears.S->FLOOR_ID != tile.FLOOR_ID && nears.E->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+TILE_SIZE, posTX.y+TILE_SIZE, HALF_SIZE, HALF_SIZE+HALF_SIZE, pos.x+HALF_SIZE, pos.y+HALF_SIZE);
            }
            if (nears.S->FLOOR_ID != tile.FLOOR_ID && nears.O->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x-HALF_SIZE, posTX.y+TILE_SIZE, HALF_SIZE, HALF_SIZE, pos.x, pos.y+HALF_SIZE);
            }
            if (nears.N->FLOOR_ID != tile.FLOOR_ID && nears.O->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x-HALF_SIZE, posTX.y-HALF_SIZE, HALF_SIZE, HALF_SIZE, pos.x, pos.y);
            }
            // outer corners
            if (nears.N->FLOOR_ID == tile.FLOOR_ID && nears.E->FLOOR_ID == tile.FLOOR_ID && nears.NE->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+TILE_SIZE, posTX.y-TILE_SIZE*1.5, HALF_SIZE, HALF_SIZE, pos.x+HALF_SIZE, pos.y);
            }
            if (nears.S->FLOOR_ID == tile.FLOOR_ID && nears.E->FLOOR_ID == tile.FLOOR_ID && nears.SE->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+TILE_SIZE, posTX.y-TILE_SIZE, HALF_SIZE, HALF_SIZE, pos.x+HALF_SIZE, pos.y+HALF_SIZE);
            }
            if (nears.S->FLOOR_ID == tile.FLOOR_ID && nears.O->FLOOR_ID == tile.FLOOR_ID && nears.SO->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+HALF_SIZE, posTX.y-TILE_SIZE, HALF_SIZE, HALF_SIZE, pos.x, pos.y+HALF_SIZE);
            }
            if (nears.N->FLOOR_ID == tile.FLOOR_ID && nears.O->FLOOR_ID == tile.FLOOR_ID && nears.NO->FLOOR_ID != tile.FLOOR_ID)
            {
                g->drawImage(texture, posTX.x+HALF_SIZE, posTX.y-TILE_SIZE*1.5, HALF_SIZE, HALF_SIZE, pos.x, pos.y);
            }
            // Game object
            if (tile.GAMEOBJECT_ID > 0)
                g->drawImage(texture, posOB.x, posOB.y, TILE_SIZE, TILE_SIZE, pos.x, pos.y);
        }
        catch (int e)
        {
            cout << "Something wrong " << endl;
        }
    }
}
