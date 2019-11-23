#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include <istream>
#include <string>
#include <sstream>
#include <iostream>

class BattleCharacter
{
    private:
        std::string charaName; //!< Member variable "charaName"
        std::string charaType; //!< Member variable "charaType"
        int level; //!< Member variable "level"
        int maxHp; //!< Member variable "maxHp"
        int hp; //!< Member variable "hp"
        int maxMp; //!< Member variable "maxMp"
        int mp; //!< Member variable "mp"
        int atk; //!< Member variable "atk"
        int mag; //!< Member variable "mag"
        int def; //!< Member variable "def"

    public:
        /** Default constructor */
        BattleCharacter(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def);

        /** Default destructor */
        virtual ~BattleCharacter();

        /** Copy constructor
         *  \param other Object to copy from
         */
        BattleCharacter(const BattleCharacter& b);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        BattleCharacter& operator=(const BattleCharacter& b);

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

        /** Access level
         * \return The current value of level
         */
        int Getlevel() const;

        /** Set level
         * \param val New value to set
         */
        void Setlevel(int val);

        /** Access hp
         * \return The current value of hp
         */
        int GetmaxHp() const;

        /** Set hp
         * \param val New value to set
         */
        void SetmaxHp(int val);

        /** Access hp
         * \return The current value of hp
         */
        int Gethp() const;

        /** Set hp
         * \param val New value to set
         */
        void Sethp(int val);

        /** Access mp
         * \return The current value of mp
         */
        int GetmaxMp() const;

        /** Set mp
         * \param val New value to set
         */
        void SetmaxMp(int val);

        /** Access mp
         * \return The current value of mp
         */
        int Getmp() const;

        /** Set mp
         * \param val New value to set
         */
        void Setmp(int val);

        /** Access atk
         * \return The current value of atk
         */
        int Getatk() const;

        /** Set atk
         * \param val New value to set
         */
        void Setatk(int val);

        /** Access mag
         * \return The current value of mag
         */
        int Getmag() const;

        /** Set mag
         * \param val New value to set
         */
        void Setmag(int val);

        /** Access def
         * \return The current value of def
         */
        int Getdef() const;

        /** Set def
         * \param val New value to set
         */
        void Setdef(int val);

        /** \brief Display all the informations about the BattleCharacter
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Make a "clone" of the BattleCharacter with all the actual attributes
         *
         * \return a new BattleCharacter
         *
         */
        virtual BattleCharacter* clone() const;

    protected:


};

#endif // BATTLECHARACTER_H
