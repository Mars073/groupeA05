#ifndef ARMOR_H
#define ARMOR_H

#include <Item.h>
#include <sstream>
#include <iostream>
#include<string>


class Armor : public Item
{
    private:
        int def; //!< Member variable "def"

    public:
        /** Default constructor */
        Armor(std::string itemName,std::string itemDescription,int def);
        /** Default destructor */
        virtual ~Armor();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Armor(const Armor& a);

        /** Access def
         * \return The current value of def
         */
        int Getdef() const;
        /** Set def
         * \param val New value to set
         */
        void Setdef(int val);

        virtual std::string toString() const;

    protected:


};

#endif // ARMOR_H
