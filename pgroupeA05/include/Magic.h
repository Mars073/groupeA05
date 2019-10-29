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
        int mpUsage;

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

        virtual std::string str() const;

        virtual Magic* clone() const;

        bool operator==(const Magic&) const;

    protected:


};

#endif // MAGIC_H
