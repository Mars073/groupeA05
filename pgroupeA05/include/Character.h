#ifndef CHARACTER_H
#define CHARACTER_H
#include <sstream>
#include <iostream>
#include<string>

class Character
{
    protected:
        std::string charaName; //!< Member variable "charaName"
        std::string charaType; //!< Member variable "charaType"

    public:
        /** Default constructor */
        Character(std::string charaName);
        /** Default destructor */
        virtual ~Character();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Character(const Character& c);

        Character& operator=(const Character& c);

        /** Access name
         * \return The current value of charaName
         */
        std::string GetcharaName() const;
        /** Set charaName
         * \param val New value to set
         */
        void SetcharaName(std::string val);
        /** Access charaType
         * \return The current value of charaType
         */
        std::string GetcharaType() const;
        /** Set charaType
         * \param val New value to set
         */
        void SetcharaType(std::string val);

        virtual std::string str() const;

        virtual Character* clone() const;

    private:


};

#endif // CHARACTER_H
