#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <Game.h>
#include <MapScene.h>
#include <FightScene.h>


class MenuScene : public Scene
{
    private:
        const unsigned short int MENU_LENGTH = 6;
        const string menu[6] = {"Back", "new Home", "new Map", "new Fight", "new Credits", "new Gameover"};
        short int selected_id = 0;

    public:
        /** Default constructor */
        MenuScene();
        /** Default destructor */
        virtual ~MenuScene();
        void draw(RenderTarget&, RenderStates) const override;
        void eventHandler(Event);

};

#endif // MENUSCENE_H
