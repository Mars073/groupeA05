#include "View/Component.h"

Component::Component(Vector2f position, Vector2f size):
    position(position)
{
    setSize(size);
}

Component::~Component()
{
    //dtor
}

void Component::setPosition(const Vector2f& _position)
{
    position =_position;
}

void Component::setSize(const Vector2f& _size)
{
    size.x = _size.x <= 0 ? 0 : _size.x;
    size.y = _size.y <= 0 ? 0 : _size.y;
}

Vector2f Component::getPosition() const
{
    return position;
}

Vector2f Component::getSize() const
{
    return size;
}
