#ifndef PLAYER_H
#define PLAYER_H

#include "BattleCharacter.h"
#include <time.h>
#include <math.h>
#include "Weapon.h"
#include "Armor.h"
#include "Inventory.h"
#include "Spells.h"

class Player : public BattleCharacter
{
    private:
        int expNow; //!< Member variable "expNow"
        int expNext; //!< Member variable "expNext"
        int money; //!< Member variable "money"
        Weapon* weapon;
        Armor* armor;
        Inventory* inventory;
        Spells* spells;
        bool checkSpellCast;

    public:
        /** Default constructor */
        Player(std::string charaName="Firion",int maxHp=200,int hp=200,int maxMp=100,int mp=100,int atk=20,int mag=10,int def=15);
        /** Default destructor */
        virtual ~Player();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Player(const Player& p);

        Player& operator=(const Player& p);

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

        /** Access weapon
         * \return The current value of weapon
         */
        Weapon* Getweapon() const;

        /** Set weapon
         * \param val New value to set
         */
        void Setweapon(Weapon* weapon);

        /** Access armor
         * \return The current value of armor
         */
        Armor* Getarmor() const;

        /** Set armor
         * \param val New value to set
         */
        void Setarmor(Armor* armor);

        /** Access inventory
         * \return The current value of inventory
         */
        Inventory* Getinventory() const;

        /** Set inventory
         * \param val New value to set
         */
        void Setinventory(Inventory* inventory);

        /** Access spells
         * \return The current value of spells
         */
        Spells* Getspells() const;

        /** Set spells
         * \param val New value to set
         */
        void Setspells(Spells* spells);

        /** Access checkSpellCast
         * \return The current value of checkSpellCast
         */
        bool GetcheckSpellCast() const;

        /** Set checkSpellCast
         * \param val New value to set
         */
        void SetcheckSpellCast(bool val);

        virtual std::string str() const;

        /** add more money to the actual amount
         * \param moneyEarn amount of money to add
         */
        void moreMoney(int moneyEarn);

        /** increase the actual level of the player
         *
         */
         void levelUp();

         /** add more exp to the actual amount
         * \param expGained amount of exp to add
         */
         void moreExp(int expGained);

         /** double the amount of exp needed for the next level
         *
         */
         void moreExpForLevelUp();

         int damageDone() const;

         int magicalDamageDone(std::string magicName);

         void damageReceived(int dmg);

         void addIntoTheBag(std::string nameItem);

         void changeEquipment(std::string nameItem);

         Player* clone() const override;

         void reduceMp(std::string magicName);

         void heals(Item* item);

         void guard(int dmg);

         void addLootMonster(std::vector<Item*>loot);

    protected:


};

#endif // PLAYER_H
