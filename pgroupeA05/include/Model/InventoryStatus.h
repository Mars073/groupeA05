#ifndef INVENTORYSTATUS_H
#define INVENTORYSTATUS_H
#include <vector>
#include <Item.h>
#include <Model/SingletonGame.h>
using namespace std;

class InventoryStatus
{
    private:
        std::vector<Item*>equipments; //!< Member variable "equipments"
        std::vector<Item*>items; //!< Member variable "items"
        Player* p; //!< Member variable "p"
    public:
        /** Default constructor */
        InventoryStatus();
        /** Default destructor */
        virtual ~InventoryStatus();
        /** Copy constructor
         *  \param other Object to copy from
         */
        InventoryStatus(const InventoryStatus& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        InventoryStatus& operator=(const InventoryStatus& other);

        /** Access equipments
         * \return The current value of equipments
         */
        std::vector<Item*> Getequipments() const;

        /** Access items
         * \return The current value of items
         */
        std::vector<Item*> Getitems() const;

        /** Access p
         * \return The current value of p
         */
        Player* Getplayer() const;

        /** delete an item from the list items
         *  \param the index of the item to delete
         */
        void deleteItem(int index);

    protected:


};

#endif // INVENTORYSTATUS_H
