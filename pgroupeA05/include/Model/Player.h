// *** ADDED BY HEADER FIXUP ***
#include <ctime>
// *** END ***
#ifndef PLAYER_H
#define PLAYER_H

#include <time.h>
#include <math.h>
#include "Model/BattleCharacter.h"
#include "Model/Weapon.h"
#include "Model/Armor.h"
#include "Model/Inventory.h"
#include "Model/Spells.h"

class Player : public BattleCharacter
{
    private:
        int expNow; //!< Member variable "expNow"
        int expNext; //!< Member variable "expNext"
        Weapon* weapon; //!< Member variable "weapon"
        Armor* armor; //!< Member variable "armor"
        Inventory* inventory; //!< Member variable "inventory"
        Spells* spells; //!< Member variable "spells"
        bool checkSpellCast; //!< Member variable "checkSpellCast"

    public:
        /** Default constructor */
        Player(std::string charaName="Firion",int maxHp=100,int hp=100,int maxMp=50,int mp=50,int atk=5,int mag=3,int def=5);

        /** Default destructor */
        virtual ~Player();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Player(const Player& p);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
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

        /** \brief Display all the informations about the Player
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

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

         /** \brief Calculate the value of the attack dealt by the Player
         *
         * \return the value of the attack dealt by the Player
         */
         int damageDone() const;

         /** \brief Calculate the value of the attack dealt by the Player when using magic and subtract it's cost from the mp of the Player
         *
         * \return the value of the attack dealt by the Player when using magic
         */
         int magicalDamageDone(std::string magicName);

         /** \brief Calculate the value of the attack received by the Monster and subtract it from the actual hp of the Player
         * \param the amount of damage the Player is gonna receive
         */
         void damageReceived(int dmg);

        /** \brief Change the equipment currently held by the Player
         *
         * \param the name of the equipment to replace the current one
         *
         */
         void changeEquipment(std::string nameItem);

         /** \brief Make a "clone" of the Player with all the actual attributes
         *
         * \return a new Player
         *
         */
         Player* clone() const override;

         /** \brief reduce the mp of the Player when using magic
          *
          * \param the name of the Magic to subtract it's mp consummation from the mp of the Player
          *
          */
         void reduceMp(std::string magicName);

         /** \brief Heal the Player with an Item and remove it from it's inventory
          *
          * \param the Item to heal the Player
          *
          */
         void heals(Item* item);

         /** \brief Reduce the damage received by 2 and heal a little bit of the hp and mp of the Player based of the amount of damage
          *
          * \param the amount of damage the Player is gonna receive
          *
          */
         void guard(int dmg);

         /** \brief Add the items given into the inventory of the Player
          *
          * \param the list of Item the Player is gonna receive
          *
          */
         void addLootMonster(std::vector<Item*>loot);

    protected:


};

#endif // PLAYER_H
