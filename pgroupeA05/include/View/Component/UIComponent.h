#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include<SFML/Graphics.hpp>
#include<Util/TexturesManager.h>
#include<Util/SoundsManager.h>
#include<Util/FontsManager.h>

using sf::Drawable;
using sf::Vector2f;
using sf::RenderTarget;
using sf::RenderStates;

class UIComponent : public Drawable
{
    protected:
        FontsManager*   fm = FontsManager::getInstance();
        SoundsManager*  sm = SoundsManager::getInstance();
        TexturesManager*tm = TexturesManager::getInstance();
        Vector2f position;
        Vector2f size;

    public:
        UIComponent(Vector2f = Vector2f(0.f, 0.f), Vector2f = Vector2f(0.f, 0.f));
        virtual ~UIComponent();
        virtual void draw(RenderTarget&, RenderStates) const = 0;
        void setPosition(const Vector2f&);
        void setSize(const Vector2f&);
        Vector2f getPosition() const;
        Vector2f getSize() const;

};

#endif // UICOMPONENT_H
