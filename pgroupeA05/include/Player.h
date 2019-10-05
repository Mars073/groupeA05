#ifndef PLAYER_H
#define PLAYER_H

#include <BattleCharacter.h>


class Player : public BattleCharacter
{
    private:

        int expNow; //!< Member variable "expNow"
        int expNext; //!< Member variable "expNext"
        int money; //!< Member variable "money"

    public:
        /** Default constructor */
        Player(std::string charaName,int hp,int mp,int atk,int mag,int def);
        /** Default destructor */
        virtual ~Player();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Player(const Player& p);

        /** Access expNow
         * \return The current value of expNow
         */
        int GetexpNow() const;
        /** Set expNow
         * \param val New value to set
         */
        void SetexpNow(int val);
        /** Access expNext
         * \return The current value of expNext
         */
        int GetexpNext() const;
        /** Set expNext
         * \param val New value to set
         */
        void SetexpNext(int val);
        /** Access money
         * \return The current value of money
         */
        int Getmoney() const;
        /** Set money
         * \param val New value to set
         */
        void Setmoney(int val);

        virtual std::string toString() const;

        void moreMoney(int moneyEarn);

    protected:


};

#endif // PLAYER_H
