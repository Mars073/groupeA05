#ifndef PANEL_H
#define PANEL_H

#include <View/Component.h>

using sf::Sprite;
using sf::IntRect;
using sf::RectangleShape;

class Panel : public Component
{
    private:
        Texture texture;
        Sprite sprites[9];

    public:
        Panel(Vector2f = Vector2f(0.f, 0.f), Vector2f = Vector2f(64.f, 64.f));
        Panel(const RectangleShape&);
        virtual ~Panel();
        void draw(RenderTarget&, RenderStates) const override;
};

#endif // PANEL_H
