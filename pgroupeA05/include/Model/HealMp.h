#ifndef HEALMP_H
#define HEALMP_H

#include "Model/HealItem.h"


class HealMp : public HealItem
{
    public:
        /** Default constructor */
        HealMp(std::string itemName,std::string itemDescription,int amountHealed);

        /** Default destructor */
        virtual ~HealMp();

        /** Copy constructor
         *  \param other Object to copy from
         */
        HealMp(const HealMp& h);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        HealMp& operator=(const HealMp& h);

        /** \brief Display all the informations about the HealMp
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Display all the informations about the HealMp to be displayed in the status menu
         *
         * \return std::string the informations
         *
         */
        std::string strEquipment() const;

        /** \brief Make a "clone" of the HealMp with all the actual attributes
         *
         * \return a new HealMp
         *
         */
        HealMp* clone() const override;

    protected:

    private:
};

#endif // HEALMP_H
