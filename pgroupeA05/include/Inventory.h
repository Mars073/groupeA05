#ifndef INVENTORY_H
#define INVENTORY_H
#include <list>
#include<string>
#include "Item.h"
#include <sstream>
#include <iostream>

class Inventory
{
    private:
        std::list<Item*>bag;

    public:
        /** Default constructor */
        Inventory();
        /** Default destructor */
        virtual ~Inventory();

        Inventory(const Inventory& i);

        void addItem(Item *item);

        std::list<Item*> Getbag() const;

        virtual std::string toString() const;
    protected:


};

#endif // INVENTORY_H
