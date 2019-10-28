#ifndef ITEM_H
#define ITEM_H
#include <sstream>
#include <iostream>
#include <string>


class Item
{
    protected:
        std::string itemName; //!< Member variable "itemName"
        std::string itemDescription; //!< Member variable "itemDescription"
        std::string itemType; //!< Member variable "itemType"

    public:
        /** Default constructor */
        Item(std::string itemName,std::string itemDescription);

        /** Default destructor */
        virtual ~Item();

        Item(const Item& i);

        Item& operator=(const Item& i);

        /** Access itemName
         * \return The current value of itemName
         */
        std::string GetitemName() const;

        /** Set itemName
         * \param val New value to set
         */
        void SetitemName(std::string val);

        /** Access itemDescription
         * \return The current value of itemDescription
         */
        std::string GetitemDescription() const;

        /** Set itemDescription
         * \param val New value to set
         */
        void SetitemDescription(std::string val);
        /** Access itemType
         * \return The current value of itemType
         */
        std::string GetitemType() const;

        /** Set itemType
         * \param val New value to set
         */
        void SetitemType(std::string val);

        virtual std::string str() const;

        virtual std::string strEquipment() const;

        virtual Item* clone() const;

        bool operator==(const Item&) const;

    private:


};

#endif // ITEM_H
