#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include <Scene.h>
#include <SFML/Graphics.hpp>


class GameoverScene: public Scene
{
    public:
        /** Default constructor */
        GameoverScene();
        /** Default destructor */
        virtual ~GameoverScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // GAMEOVERSCENE_H
