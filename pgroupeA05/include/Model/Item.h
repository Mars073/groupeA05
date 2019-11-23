// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#ifndef ITEM_H
#define ITEM_H
#include <sstream>
#include <iostream>
#include <string>


class Item
{
    private:
        std::string itemName; //!< Member variable "itemName"
        std::string itemDescription; //!< Member variable "itemDescription"
        std::string itemType; //!< Member variable "itemType"

    public:
        /** Default constructor */
        Item(std::string itemName,std::string itemDescription);

        /** Default destructor */
        virtual ~Item();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Item(const Item& item);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Item& operator=(const Item& item);

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

        /** \brief Display all the informations about the Item
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Display the informations about the Item to be displayed in the status menu
         *
         * \return std::string the informations
         *
         */
        virtual std::string strEquipment() const;

        /** \brief Make a "clone" of the Item with all the actual attributes
         *
         * \return a new Item
         *
         */
        virtual Item* clone() const;

        /** \brief Allow to check if 2 Item are the same based on their name
         *
         * \param The Item to check if it's the same
         * \return True if it's the same, False if it's not
         *
         */
        bool operator==(const Item&) const;

    protected:


};

#endif // ITEM_H
