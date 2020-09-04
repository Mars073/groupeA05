#ifndef HEAL_H
#define HEAL_H
#include "Model/HealItem.h"



class Heal : public HealItem
{
    private:


    public:
        /** Default constructor */
        Heal(std::string itemName,std::string itemDescription,int amountHealed);

        /** Default destructor */
        virtual ~Heal();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Heal(const Heal& h);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Heal& operator=(const Heal& h);

        /** \brief Display all the informations about the Heal
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Display all the informations about the Heal to be displayed in the status menu
         *
         * \return std::string the informations
         *
         */
        std::string strEquipment() const;

        /** \brief Make a "clone" of the Heal with all the actual attributes
         *
         * \return a new Heal
         *
         */
        Heal* clone() const override;

    protected:


};

#endif // HEAL_H
