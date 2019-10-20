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

    public:
        /** Default constructor */
        Magic(std::string mName,int baseDamage);

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

        virtual std::string str() const;

    protected:


};

#endif // MAGIC_H
