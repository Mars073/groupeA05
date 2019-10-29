#ifndef HEAL_H
#define HEAL_H
#include <HealItem.h>



class Heal : public HealItem
{
    private:


    public:
        /** Default constructor */
        Heal(std::string itemName,std::string itemDescription,int amountHealed);

        /** Default destructor */
        virtual ~Heal();

        Heal(const Heal& h);

        Heal& operator=(const Heal& h);

        virtual std::string str() const;

        std::string strEquipment() const;

        Heal* clone() const override;

    protected:


};

#endif // HEAL_H
