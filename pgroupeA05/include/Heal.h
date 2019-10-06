#ifndef HEAL_H
#define HEAL_H

#include <sstream>
#include <iostream>
#include<string>
#include <Item.h>



class Heal : public Item
{
    private:
        int amountHealed; //!< Member variable "amountHealed"

    public:
        /** Default constructor */
        Heal(std::string itemName,std::string itemDescription,int amountHealed);
        /** Default destructor */
        virtual ~Heal();

        Heal(const Heal& h);

        /** Access amountHealed
         * \return The current value of amountHealed
         */
        int GetamountHealed() const;
        /** Set amountHealed
         * \param val New value to set
         */
        void SetamountHealed(int val);

        virtual std::string toString() const;

    protected:


};

#endif // HEAL_H