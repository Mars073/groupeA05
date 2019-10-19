#ifndef MONSTER_H
#define MONSTER_H

#include <BattleCharacter.h>


class Monster : public BattleCharacter
{
    private:
        int moneyHeld; //!< Member variable "moneyHeld"
        int expHeld; //!< Member variable "expHeld"

    public:
        /** Default constructor */
        Monster(std::string charaName,int hp,int mp,int atk,int mag,int def,int level,int moneyHeld,int expHeld);
        /** Default destructor */
        virtual ~Monster();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Monster(const Monster& m);

        Monster& operator=(const Monster& m);

        /** Access moneyHeld
         * \return The current value of moneyHeld
         */
        int GetmoneyHeld() const;
        /** Set moneyHeld
         * \param val New value to set
         */
        void SetmoneyHeld(int val);
        /** Access expHeld
         * \return The current value of expHeld
         */
        int GetexpHeld() const;
        /** Set expHeld
         * \param val New value to set
         */
        void SetexpHeld(int val);

        virtual std::string str() const;

    protected:


};

#endif // MONSTER_H
