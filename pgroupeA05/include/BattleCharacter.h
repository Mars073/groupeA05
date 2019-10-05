#ifndef BATTLECHARACTER_H
#define BATTLECHARACTER_H

#include <Character.h>

class BattleCharacter : public Character
{
    protected:
        int level; //!< Member variable "level"
        int hp; //!< Member variable "hp"
        int mp; //!< Member variable "mp"
        int atk; //!< Member variable "atk"
        int mag; //!< Member variable "mag"
        int def; //!< Member variable "def"

    public:
        /** Default constructor */
        BattleCharacter(std::string charaName,int hp,int mp,int atk,int mag,int def);
        /** Default destructor */
        virtual ~BattleCharacter();
        /** Copy constructor
         *  \param other Object to copy from
         */
        BattleCharacter(const BattleCharacter& b);

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
        int Gethp() const;
        /** Set hp
         * \param val New value to set
         */
        void Sethp(int val);
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

        virtual std::string toString() const;

        void damageReceived(int dmg);

        int damageDone(int atkWeapon,int defEnemy);

    private:


};

#endif // BATTLECHARACTER_H
