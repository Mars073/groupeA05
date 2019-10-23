#include "View/DrawablePlayer.h"

DrawablePlayer::DrawablePlayer(/*const Player& player*/)/*:Player(player)*/
{
    orientation = 0;
    move_at = 0;
    clock.restart();
}

DrawablePlayer::~DrawablePlayer()
{
    //dtor
}

void DrawablePlayer::draw(sf::RenderTarget&target, sf::RenderStates) const
{
    // for debug only::
    sf::Sprite sp;
    sf::Texture tx;
    tx.loadFromFile("data/images/character_sprite.png");
    int delta_anim = clock.getElapsedTime().asMilliseconds() - move_at;
    int y =
        orientation == 0 ? 108 :
            orientation == 1 ? 73 :
                orientation == 3 ? 38 : 3;
    int x =
        delta_anim < 300 ?
            delta_anim < 200 ?
                delta_anim < 100 ? 1 : 33 : 65 : 33;
    SingletonGame::getInstance()->drawImage(tx, x, y, 32, 32, getPosition().x*32, getPosition().y*32-8);
}

void DrawablePlayer::move(const float x, const float y)
{
    move(Vector2f(x, y));
}

void DrawablePlayer::move(const Vector2f& movement)
{
    Time now = clock.getElapsedTime();
    if (now.asMilliseconds() - move_at < 300)
        return;
    old_position = position;
    position+= movement;
    move_at = now.asMilliseconds();
}

sf::Vector2f DrawablePlayer::getPosition() const
{
    Time now = clock.getElapsedTime();
    float progress = std::min(1.f, (now.asMilliseconds() - move_at)/300.f);
    Vector2f delta_position = position - old_position;
    return Vector2f(
        old_position.x + delta_position.x*progress,
        old_position.y + delta_position.y*progress
    );
}

sf::Vector2f DrawablePlayer::getRelativePosition() const
{
    return Vector2f(position.x*32, position.y*32);
}

sf::Vector2f DrawablePlayer::getAbsolutePosition() const
{
    return Vector2f(position.x, position.y);
}

void DrawablePlayer::setPosition(const float x, const float y)
{
    setPosition(Vector2f(x, y));
}

void DrawablePlayer::setPosition(const Vector2f& _position)
{
    position = old_position = _position;
    move_at=0; // clear animation
}

void DrawablePlayer::flip()
{
    setOrientation(orientation + 2);
}

void DrawablePlayer::setOrientation(const short _orientation)
{
    orientation = _orientation % 4;
}

short DrawablePlayer::getOrientation() const
{
    return orientation;
}
