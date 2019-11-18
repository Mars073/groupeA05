#ifndef ARMOR_H
#define ARMOR_H
#include <Item.h>



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

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Armor& operator=(const Armor& a);

        /** Access def
         * \return The current value of def
         */
        int Getdef() const;

        /** Set def
         * \param val New value to set
         */
        void Setdef(int val);


        /** \brief Display all the informations about the Armor
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Display the informations about the Armor to be displayed in the status menu
         *
         * \return std::string the informations
         *
         */
        std::string strEquipment() const;

        /** \brief Make a "clone" of the armor with all the actual attributes
         *
         * \return a new Armor
         *
         */
        Armor* clone() const override;

    protected:


};

#endif // ARMOR_H
