#ifndef HEALITEM_H
#define HEALITEM_H

#include <Item.h>


class HealItem : public Item
{
    private:
        int amountHealed; //!< Member variable "amountHealed"

    public:
        /** Default constructor */
        HealItem(std::string itemName,std::string itemDescription,int amountHealed);
        /** Default destructor */
        virtual ~HealItem();
        /** Copy constructor
         *  \param other Object to copy from
         */
        HealItem(const HealItem& h);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        HealItem& operator=(const HealItem& other);

        /** Access amountHealed
         * \return The current value of amountHealed
         */
        int GetamountHealed() const;
        /** Set amountHealed
         * \param val New value to set
         */
        void SetamountHealed(int val);

        virtual std::string str() const;

        virtual std::string strEquipment() const;

        HealItem* clone() const override;

    protected:


};

#endif // HEALITEM_H
