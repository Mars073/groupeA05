// *** ADDED BY HEADER FIXUP ***
#include <string>
// *** END ***
#ifndef WINDOWSTATUS_H
#define WINDOWSTATUS_H
#include <string.h>
#include <SFML/Graphics.hpp>
#include <Model/SingletonGame.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;
class WindowStatus: public StrategyScene
{
    private:
        const unsigned short int MENU_LENGTH = 4; //!< Member variable "MENU_LENGTH"
        const string menu[4] = {"STATUS", "EQUIPMENT", "ITEMS", "RETURN TO GAME"}; //!< Member variable "menu"
        short int selected_id = 0; //!< Member variable "selected_id"
        RectangleShape rectAll; //!< Member variable "rectAll"
        RectangleShape rectMenu; //!< Member variable "rectMenu"
        Player* p; //!< Member variable "p"
        int choiceMenu; //!< Member variable "choiceMenu"
        short int selected_id_menu = 0; //!< Member variable "selected_id_menu"
        short int selected_id_items = 0; //!< Member variable "selected_id_items"
        std::vector<Item*>equipments; //!< Member variable "equipments"
        std::vector<Item*>items; //!< Member variable "items"


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

        /** \brief Draw every element in the scene
         *
         * \param
         * \param
         */

        void draw(RenderTarget&, RenderStates) const override;

        /** \brief Draw the items in the status menu of the character
         *
         * \param
         * \param
         * \param the index of the first element to be displayed
         * \param the index of the last element to be displayed
         * \param the list of items to be displayed
         * \param the item type of the first type of item
         * \param the item type of the second type of item
         * \param the text displayed of the first type of item
         * \param the text displayed of the second type of item
         * \param the index of the actual position in the menu
         */
        void drawItems(RenderTarget& target, RenderStates states,int nb1,int nb2,std::vector<Item*>listofItem,std::string type1,std::string type2,std::string type1Desc,std::string type2Desc,short int id) const;

        //void drawEquipment(RenderTarget&, RenderStates,int nb,int nb2) const;

        /** \brief Handle all the event that happens in the scene (ex: a key pressed)
         *
         * \param the actual event
         */
        void eventHandler(Event event);

        /** \brief Allow to find the index of the item to erase it in the local list
         *
         * \param the item to find the index
         * \return the index of the item in the local list
         */
        int indexOfHeal(Item*) const;

    protected:


};

#endif // WINDOWSTATUS_H
