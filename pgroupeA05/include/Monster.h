// *** ADDED BY HEADER FIXUP ***
#include <ctime>
// *** END ***
#ifndef MONSTER_H
#define MONSTER_H

#include "BattleCharacter.h"
#include "Inventory.h"
#include <time.h>

class Monster : public BattleCharacter
{
    private:
        int expHeld; //!< Member variable "expHeld"
        std::vector<Item*>lootHeld; //!< Member variable "lootHeld"
        std::vector<int>percentagesItem; //!< Member variable "percentagesItem"

    public:
        /** Default constructor */
        Monster(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def,int level,int expHeld);

        /** Default destructor */
        virtual ~Monster();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Monster(const Monster& m);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Monster& operator=(const Monster& m);

        /** Access expHeld
         * \return The current value of expHeld
         */
        int GetexpHeld() const;

        /** Set expHeld
         * \param val New value to set
         */
        void SetexpHeld(int val);

        /** \brief Display all the informations about the Monster
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** \brief Calculate the value of the attack dealt by the monster
         *
         * \return the value of the attack dealt by the monster
         */
        int damageDone() const;

        /** \brief Calculate the value of the attack received by the player and subtract it from the actual hp of the monster
         * \param the amount of damage the monster is gonna receive
         */
        void damageReceived(int dmg);

        /** \brief Make a "clone" of the Monster with all the actual attributes
         *
         * \return a new Monster
         *
         */
        Monster* clone() const override;

        /** \brief Allow to check if 2 Monster are the same based on their name
         *
         * \param The Monster to check if it's the same
         * \return True if it's the same, False if it's not
         *
         */
        bool operator==(const Monster&) const;

        /** Access lootHeld
         * \return The current value of lootHeld
         */
        std::vector<Item*> GetLootHeld() const;

        /** Set lootHeld
         * \param val New value to set
         */
        void SetLootHeld(std::vector<Item*> val);

        /** add an item in the list of item of the monster
         *  \param the item to add in the list of item of the monster
         */
        void addLoot(Item* item);

        /** Access percentagesItem
         * \return The current value of percentagesItem
         */
        std::vector<int> GetPercentagesItem() const;

        /** Set percentagesItem
         * \param val New value to set
         */
        void SetPercentagesItem(std::vector<int> val);

        /** add a number in the list of percentages of the items held by the monster
         *  \param the number to add in the list of percentages of the items held by the monster
         */
        void addPercentage(int nb);

        /** \brief Show as a number the value of the damage received by the monster without changing it's hp
         *
         * \param the amount of damage the monster is gonna receive
         * \return the value of the damage received by the monster
         *
         */
        int showDamageReceived(int dmg);

        /** \brief Calculate, based on the percentages of each item, if they are to be given to the player or not
         *
         * \return a list of item to be given to the player
         *
         */
        std::vector<Item*> giveLoot();

    protected:


};

#endif // MONSTER_H
