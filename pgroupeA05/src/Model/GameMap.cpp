#include "Model/GameMap.h"
#define PI 3.141592653589793

GameMap::GameMap()
{
    setTexture(Resources::getTexture("simplemap", "data/images/simplemap_sprite.png"));
    setWidth(64);
    world = 0;
}
GameMap::GameMap(int width)
{
    setWidth(width);
}

void GameMap::spawn()
{
    clock.restart();
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
   //dataset.resize(width*width, TileInfo());
   dataset.clear();
   for (unsigned i = 0; i < width*width; i++)
        dataset.push_back(TileInfo(i, 0));
}

unsigned GameMap::getWidth() const
{
    return width;
}

bool GameMap::loadFromFile(string path)
{
    try
    {
        unsigned i = 0;
        char32_t c;
        locale loc (locale(), new codecvt_utf8<char32_t>);
        basic_ifstream<char32_t> fdat(path, ios::binary);
        fdat.imbue(loc);
        string header;
        for (unsigned ii = 0; ii < 3 && fdat.get(c); ii++)
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
            TileInfo current = TileInfo(i++, c-48);
            if (current.GAMEOBJECT_ID == GUID_RANDOM_TELEPORTER)
                random_teleporters.push_back(i);
            dataset.push_back(current);
        }
        cout << "map blocks: " << dataset.size() << endl;
        return true;
    }
    catch (int e)
    {
        return false;
    }
}

bool GameMap::loadFromFileID(unsigned _world)
{
    if (loadFromFile("data/maps/world_" + to_string(_world) + ".bin"))
    {
        world = _world;
        return true;
    }
    else
    {
        return false;
    }
}

TileInfo GameMap::xy2t(const Vector2f vec) const
{
    return dataset.at((unsigned)(vec.y*width+vec.x));
}

unsigned GameMap::xy2i(const Vector2f vec) const
{
    return vec.x/TILE_SIZE + vec.y/TILE_SIZE*width;
}

Vector2f GameMap::i2xy(const unsigned index) const
{
    return Vector2f((index%width)*TILE_SIZE, (index/width)*TILE_SIZE);
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

GameMap::neighboursInfo GameMap::getNeighboursInfo(const unsigned index) const
{
    neighboursInfo tmp;
    const TileInfo* self = dataset.data() + index;
    tmp.N = dataset.data() + (index < width ? index : index - width);
    tmp.E = dataset.data() + ((index + 1)%width == 0 ? index : index + 1);
    tmp.S = dataset.data() + (index+width >= dataset.size() ? index : index + width);
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

    for (unsigned i = max(xy2i(vw), width)-width; i < dataset.size(); i++)
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
    if (now.asMilliseconds() < 300)
    {
        RectangleShape rect(Vector2f(width*TILE_SIZE, width*TILE_SIZE));
        rect.setFillColor(Color(0, 0, 0, (300-now.asMilliseconds())/300.*255));
        g->getWindow()->draw(rect);
    }
}

void GameMap::interact(Player& player, const TileInfo* tile,  GameMap& bypass) const
{
    unsigned UID = tile->INDEX;
    switch (tile->GAMEOBJECT_ID)
    {
    case GUID_RANDOM_TELEPORTER:
        {
            srand(time(NULL));
            unsigned tid = rand() % random_teleporters.size();
            Vector2f new_pos = i2xy(random_teleporters.at(tid));
            player.setPosition(new_pos.x/32-1, new_pos.y/32);
            bypass.spawn();
            break;
        }
    case 201://TENT
    case 132://LARGE_DOOR
    case GUID_DOORS:
        {
            //cout << "[" << UID << "] " << player.getAbsolutePosition().x << "; " << player.getAbsolutePosition().y << endl;
            if (world == 0)
            {
                switch(UID)
                {
                case 11462: // Kot de Kévin
                    {
                        player.setPosition(15, 10);
                        bypass.loadFromFileID(1);
                        break;
                    }
                case 959:  // Castle
                case 960:
                    {
                        break;
                    }
                case 5405: // PUB
                    {
                        player.setPosition(10, 53);
                        bypass.loadFromFileID(1);
                        break;
                    }
                case 7071: // Right House (Village)
                    {
                        player.setPosition(31, 10);
                        bypass.loadFromFileID(1);
                        break;
                    }
                case 7081: // Left House (Village)
                    {
                        player.setPosition(15, 10);
                        bypass.loadFromFileID(1);
                        break;
                    }
                default: return;
                }
            }
            else if (world == 1)
            {
                switch(UID)
                {
                case 591: // Right House (Village)
                    {
                        player.setPosition(41, 56);
                        bypass.loadFromFileID(0);
                        break;
                    }
                case 607: // Left House (Village)4096
                    {
                        player.setPosition(31, 56);
                        bypass.loadFromFileID(0);
                        break;
                    }
                case 1: // TENT
                    {
                        player.setPosition(70, 90);
                        bypass.loadFromFileID(0);
                        break;
                    }
                case 3338: // PUB
                    {
                        player.setPosition(29, 43);
                        bypass.loadFromFileID(0);
                        break;
                    }
                default: return;
                }
            }
            bypass.spawn();
            player.flip();
            break;

        }
    default:break;
    }
}
