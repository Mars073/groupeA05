#ifndef WINDOWSTATUS_H
#define WINDOWSTATUS_H
#include <string.h>
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include <Model/SingletonGame.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <View/Scenes/WindowEquipment.h>
using namespace sf;
using namespace std;
class WindowStatus: public StrategyScene
{
    private:
        const unsigned short int MENU_LENGTH = 4;
        const string menu[4] = {"STATUS", "EQUIPMENT", "ITEMS", "RETURN TO GAME"};
        short int selected_id = 0;
        RectangleShape rectAll;
        RectangleShape rectMenu;
        Player* p;
        int choiceMenu;
        short int selected_id_menu = 0;
        std::vector<Item*>equipments;

    public:
        /** Default constructor */
        WindowStatus();
        /** Default destructor */
        virtual ~WindowStatus();
        /** Copy constructor
         *  \param other Object to copy from
         */
        WindowStatus(const WindowStatus& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        WindowStatus& operator=(const WindowStatus& other);

        void draw(RenderTarget&, RenderStates) const override;

        void eventHandler(Event event);

    protected:


};

#endif // WINDOWSTATUS_H
