// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#ifndef MAGIC_H
#define MAGIC_H
#include <sstream>
#include <iostream>
#include <string>

class Magic
{
    private:
        std::string mName; //!< Member variable "mName"
        int baseDamage; //!< Member variable "baseDamage"
        int mpUsage; //!< Member variable "mpUsage"

    public:
        /** Default constructor */
        Magic(std::string mName,int baseDamage,int mpUsage);

        /** Default destructor */
        virtual ~Magic();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Magic(const Magic& m);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Magic& operator=(const Magic& m);

        /** Access mName
         * \return The current value of mName
         */
        std::string GetmName()const;

        /** Set mName
         * \param val New value to set
         */
        void SetmName(std::string val);

        /** Access baseDamage
         * \return The current value of baseDamage
         */
        int GetbaseDamage()const;

        /** Set baseDamage
         * \param val New value to set
         */
        void SetbaseDamage(int val);

        /** Access mpUsage
         * \return The current value of mpUsage
         */
        int GetmpUsage()const;

        /** Set mpUsage
         * \param val New value to set
         */
        void SetmpUsage(int val);

        /** \brief Display all the informations about the Magic
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Make a "clone" of the Magic with all the actual attributes
         *
         * \return a new Magic
         *
         */
        virtual Magic* clone() const;

        /** \brief Allow to check if 2 Magic are the same based on their name
         *
         * \param The Magic to check if it's the same
         * \return True if it's the same, False if it's not
         *
         */
        bool operator==(const Magic&) const;

    protected:


};

#endif // MAGIC_H
