#ifndef WEAPON_H
#define WEAPON_H
#include "Model/Item.h"


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

        /** Copy constructor
         *  \param other Object to copy from
         */
        Weapon(const Weapon& w);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Weapon& operator=(const Weapon& w);

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

        /** \brief Display all the informations about the Weapon
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Display the informations about the Weapon to be displayed in the status menu
         *
         * \return std::string the informations
         *
         */
        std::string strEquipment() const;

        /** \brief Make a "clone" of the Weapon with all the actual attributes
         *
         * \return a new Armor
         *
         */
        Weapon* clone() const override;

    protected:


};

#endif // WEAPON_H
