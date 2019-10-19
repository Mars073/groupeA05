#ifndef INVENTORY_H
#define INVENTORY_H
#include <list>
#include "Item.h"


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

        Inventory& operator=(const Inventory& i);

        void addItem(Item *item);

        std::list<Item*> Getbag() const;

        virtual std::string str() const;
    protected:


};

#endif // INVENTORY_H
