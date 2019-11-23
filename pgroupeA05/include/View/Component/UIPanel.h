#ifndef UIPANEL_H
#define UIPANEL_H

#include <View/Component/UIComponent.h>

using sf::Sprite;
using sf::IntRect;
using sf::RectangleShape;

class UIPanel : public UIComponent
{
    private:
        Texture texture;
        Sprite sprites[9];

    public:
        UIPanel(Vector2f = Vector2f(0.f, 0.f), Vector2f = Vector2f(64.f, 64.f));
        UIPanel(const RectangleShape&);
        virtual ~UIPanel();
        void draw(RenderTarget&, RenderStates) const override;
};

#endif // UIPANEL_H
