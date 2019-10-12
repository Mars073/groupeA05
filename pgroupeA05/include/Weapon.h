#ifndef WEAPON_H
#define WEAPON_H

#include <Item.h>
#include <sstream>
#include <iostream>
#include<string>

class Weapon : public Item
{
    private:
        int atk; //!< Member variable "atk"
        int mag; //!< Member variable "mag"

    public:
        /** Default constructor */
        Weapon(std::string itemName,std::string itemDescription,int atk,int mag);
        /** Default destructor */
        virtual ~Weapon();

        Weapon(const Weapon& w);

        /** Access atk
         * \return The current value of atk
         */
        int Getatk() const;
        /** Set atk
         * \param val New value to set
         */
        void Setatk(int val);
        /** Access mag
         * \return The current value of mag
         */
        int Getmag() const;
        /** Set mag
         * \param val New value to set
         */
        void Setmag(int val);

        virtual std::string str() const;

    protected:


};

#endif // WEAPON_H
