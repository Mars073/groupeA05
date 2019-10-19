#ifndef INVENTORY_H
#define INVENTORY_H
#include <list>
#include <fstream>
#include <algorithm>
#include "Item.h"
#include "Heal.h"
#include "Armor.h"
#include "Weapon.h"

class Inventory
{
    private:
        std::list<Item*>bag;
        std::list<Item*>everyItems;

    public:
        /** Default constructor */
        Inventory();
        /** Default destructor */
        virtual ~Inventory();

        Inventory(const Inventory& i);

        Inventory& operator=(const Inventory& i);

        void addItem(Item *item);

        void addItem(std::string itemName);

        void addItemInFile(Item *item);

        std::list<Item*> Getbag() const;

        virtual std::string str() const;

        /** read the file "items.txt" in "data/lists" and add them as items in the bag
         *
         */
        void readFromFile();

        /** write in the file "items.txt" in "data/lists"
         *
         */
        void writeInFile();

        /** return the item with the name in the argument
         *  \param the name of the item to return
         */
        Item* getOneItem(std::string name);
    protected:


};

#endif // INVENTORY_H
