#ifndef HEALMP_H
#define HEALMP_H

#include <HealItem.h>


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

        virtual std::string str() const;

        std::string strEquipment() const;

        HealMp* clone() const override;

    protected:

    private:
};

#endif // HEALMP_H
