#ifndef DRAWABLEPLAYER_H
#define DRAWABLEPLAYER_H

#include <SFML/Graphics.hpp>
#include <Model/SingletonGame.h>
//#include <Player.h>

using sf::Drawable;
using sf::Vector2f;
using sf::Clock;
using sf::Time;

class DrawablePlayer : public Drawable/*, public Player*/
{
    private:
        Clock clock; //!< Member variable "clock"
        Vector2f old_position; //!< Member variable "old_position"
        Vector2f position; //!< Member variable "position"
        short orientation; //!< Member variable "orientation"
        int move_at; //!< Member variable "move_at"
    public:
        DrawablePlayer(/*const Player& = Player("Drawable Player", 0, 0, 0, 0, 0)*/);
        virtual ~DrawablePlayer();

        /** Draw player */
        void draw(sf::RenderTarget&, sf::RenderStates) const;
        /** Access Position
         * \return The current position
         */
        sf::Vector2f getPosition() const;
        sf::Vector2f getRelativePosition() const;
        sf::Vector2f getAbsolutePosition() const;
        /** Move player */
        void move(const float, const float);
        void move(const sf::Vector2f&);
        /** Set current position */
        void setPosition(const float, const float);
        void setPosition(const sf::Vector2f&);
        /** Set player orientation */
        void setOrientation(const short);
        /** 180° player rotation */
        void flip();
        /** Access Orientation */
        short getOrientation() const;
};

#endif // DRAWABLEPLAYER_H
