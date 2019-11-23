#include "View/Component/UIComponent.h"

UIComponent::UIComponent(Vector2f position, Vector2f size):
    position(position)
{
    setSize(size);
}

UIComponent::~UIComponent()
{
    //dtor
}

void UIComponent::setPosition(const Vector2f& _position)
{
    position =_position;
}

void UIComponent::setSize(const Vector2f& _size)
{
    size.x = _size.x <= 0 ? 0 : _size.x;
    size.y = _size.y <= 0 ? 0 : _size.y;
}

Vector2f UIComponent::getPosition() const
{
    return position;
}

Vector2f UIComponent::getSize() const
{
    return size;
}
