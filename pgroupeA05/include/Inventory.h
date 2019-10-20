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
        std::list<Item*>bag; //list of items ingame
        std::list<Item*>everyItems; //list of every items from the files

    public:
        /** Default constructor */
        Inventory();
        /** Default destructor */
        virtual ~Inventory();

        Inventory(const Inventory& i);

        Inventory& operator=(const Inventory& i);

        /** add an item in the bag ingame not in the file
         *  \param the item to add ingame
         */
        void addItem(Item *item);

        /** add an item in the bag ingame not in the file
         *  \param the name of the item from the file to add ingame
         */
        void addItem(std::string itemName);

        /** add an item in the file not in the bag ingame
         *  \param the item to add in the file
         */
        void addItemInFile(Item *item);

        std::list<Item*> Getbag() const;

        std::list<Item*> GeteveryItems() const;

        virtual std::string str() const;

        /** read the file "items.txt" in "data/lists" and add them as items in the everyItems list
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

        /** allow to change the attributes of an item and write it in the file of that type of item
         *  \param nameItem the name of the item to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name, "description" for its description,
         *  "heal" for the amount healed by an heal item, "def" for the def of an armor, "atk" for the atk of a weapon or
         *  "mag" for the magical power of a weapon
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameItem,std::string nameAttribute,std::string val);

        /** allow to change the attributes of an item and write it in the file of that type of item
         *  \param nameItem the name of the item to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name, "description" for its description,
         *  "heal" for the amount healed by an heal item, "def" for the def of an armor, "atk" for the atk of a weapon or
         *  "mag" for the magical power of a weapon
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameItem,std::string nameAttribute,int val);

        /** delete an item from the list ingame
         *  \param the name of the item to delete
         */
        void deleteItem(std::string nameItem);

        /** delete an item from the list in the file
         *  \param the name of the item to delete
         */
        void deleteItemInFile(std::string nameItem);
    protected:


};

#endif // INVENTORY_H
