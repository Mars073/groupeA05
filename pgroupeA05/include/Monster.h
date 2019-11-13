#ifndef MONSTER_H
#define MONSTER_H

#include "BattleCharacter.h"
#include "Inventory.h"
#include <time.h>

class Monster : public BattleCharacter
{
    private:
        int moneyHeld; //!< Member variable "moneyHeld"
        int expHeld; //!< Member variable "expHeld"
        Inventory* inventory;
        std::vector<int>percentagesItem;

    public:
        /** Default constructor */
        Monster(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def,int level,int moneyHeld,int expHeld);
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

        int damageDone() const;

        void damageReceived(int dmg);

        Monster* clone() const override;

        bool operator==(const Monster&) const;

        /** Access inventory
         * \return The current value of inventory
         */
        Inventory* Getinventory() const;

        /** Set inventory
         * \param val New value to set
         */
        void Setinventory(Inventory* inventory);

        /** Access inventory
         * \return The current value of inventory
         */
        std::vector<int> GetPercentagesItem() const;

        /** Set inventory
         * \param val New value to set
         */
        void SetPercentagesItem(std::vector<int> val);

        void addPercentage(int nb);

        int showDamageReceived(int dmg);

        std::vector<Item*> giveLoot();

    protected:


};

#endif // MONSTER_H
