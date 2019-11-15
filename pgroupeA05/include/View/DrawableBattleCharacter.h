#ifndef DRAWABLEBATTLECHARACTER_H
#define DRAWABLEBATTLECHARACTER_H

#include <SFML/Graphics.hpp>
#include <Util/FontsManager.h>
#include <Util/TexturesManager.h>
#include <BattleCharacter.h>

using sf::Drawable;
using sf::Vector2f;
using sf::Sprite;
using sf::Text;
using sf::RectangleShape;
using sf::Color;

class DrawableBattleCharacter : public Drawable
{
    private:
        FontsManager*   fm = FontsManager::getInstance();
        TexturesManager*tm = TexturesManager::getInstance();

        BattleCharacter* character = nullptr;
        Vector2f position = Vector2f(.0, .0);
        Texture texture;
    public:
        /** Constants */
        static const int B_WIDTH = 100;
        static const int B_HEIGHT = 24;
        /** Default constructor */
        DrawableBattleCharacter(BattleCharacter* = nullptr, Vector2f = Vector2f(.0, .0));
        void setCharacter();
        /** Default destructor */
        virtual ~DrawableBattleCharacter();
        void draw(sf::RenderTarget&, sf::RenderStates) const;
        void setPosition(int, int);
        void setPosition(float, float);
        void setPosition(Vector2f);
        void setCharacter(BattleCharacter*);
};

#endif // DRAWABLEBATTLECHARACTER_H
