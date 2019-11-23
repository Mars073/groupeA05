#include "View/Components/Panel.h"

Panel::Panel(Vector2f position, Vector2f size):
    Component(position, size)
{
    texture = *tm->get("ui_panel");

    /** set texture part */
    for (Sprite& sprite: sprites)
        sprite.setTexture(texture);
    sprites[0].setTextureRect(IntRect(0, 0, 16, 16));       // TOP LEFT CORNER
    sprites[0].setPosition(position);
    sprites[1].setTextureRect(IntRect(16, 0, 96, 16));      // TOP
    sprites[1].setPosition(position + Vector2f(16, 0));
    sprites[1].setScale((size.x-32.f)/96.f, 1.f);
    sprites[2].setTextureRect(IntRect(112, 0, 16, 16));     // TOP RIGHT CORNER
    sprites[2].setPosition(position + Vector2f(size.x-16, 0));

    sprites[3].setTextureRect(IntRect(0, 16, 16, 96));      // LEFT
    sprites[3].setPosition(position + Vector2f(0, 16));
    sprites[3].setScale(1.f, (size.y-32.f)/96.f);
    sprites[4].setTextureRect(IntRect(112, 16, 16, 96));    // RIGHT
    sprites[4].setPosition(position + Vector2f(size.x-16, 16));
    sprites[4].setScale(1.f, (size.y-32.f)/96.f);

    sprites[5].setTextureRect(IntRect(16, 16, 96, 96));     // MIDDLE
    sprites[5].setPosition(position + Vector2f(16, 16));
    sprites[5].setScale((size.x-32.f)/96.f, (size.y-32.f)/96.f);

    sprites[6].setTextureRect(IntRect(0, 112, 16, 16));     // BOTTOM LEFT CORNER
    sprites[6].setPosition(position + Vector2f(0, size.y-16));
    sprites[7].setTextureRect(IntRect(16, 112, 96, 16));    // BOTTOM
    sprites[7].setPosition(position + Vector2f(16, size.y-16));
    sprites[7].setScale((size.x-32.f)/96.f, 1.f);
    sprites[8].setTextureRect(IntRect(112, 112, 16, 16));   // BOTTOM LEFT CORNER
    sprites[8].setPosition(position + Vector2f(size.x-16, size.y-16));
}

Panel::Panel(const RectangleShape& shape):
    Panel(shape.getPosition(), shape.getSize())
{
    // ctor
}

Panel::~Panel()
{

}

void Panel::draw(RenderTarget& target, RenderStates states) const
{
    for (const Sprite& sprite: sprites)
        target.draw(sprite);
    //target.draw(sprites[0]);
}
