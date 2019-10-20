#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <Game.h>
#include "BattleCharacter.h"
#include <time.h>
#include <math.h>
#include "Weapon.h"
#include "Armor.h"
#include "Inventory.h"
#include "Spells.h"

class Player : public BattleCharacter, public sf::Drawable
{
    private:
        Vector2f old_position; //!< Member variable "old_position"
        Vector2f position; //!< Member variable "position"
        short orientation; //!< Member variable "orientation"
        Clock clock; //!< Member variable "clock"
        int move_at; //!< Member variable "move_at"
        int expNow; //!< Member variable "expNow"
        int expNext; //!< Member variable "expNext"
        int money; //!< Member variable "money"
        /*Weapon weapon;
        Armor armor;*/
        Inventory inventory;
        Spells spells;

    public:
        /** Default constructor */
        Player(std::string charaName,int hp,int mp,int atk,int mag,int def);
        /** Default destructor */
        virtual ~Player();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Player(const Player& p);

        Player& operator=(const Player& p);

        /** Draw player */
        void draw(sf::RenderTarget&, sf::RenderStates) const;
        /** Access Position
         * \return The current position
         */
        sf::Vector2f getPosition() const;
        sf::Vector2f getRelativePosition() const;
        sf::Vector2f getAbsolutePosition() const;
        /** Move player */
        void move(const float, const float);
        void move(const sf::Vector2f&);
        /** Set current position */
        void setPosition(const float, const float);
        void setPosition(const sf::Vector2f&);
        /** Set player orientation */
        void setOrientation(const short);
        /** 180° player rotation */
        void flip();
        /** Access Orientation */
        short getOrientation() const;
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
        //Weapon Getweapon() const;

        /** Set weapon
         * \param val New value to set
         */
        //void Setweapon(Weapon weapon);

        /** Access armor
         * \return The current value of armor
         */
        //Armor Getarmor() const;

        /** Set armor
         * \param val New value to set
         */
        //void Setarmor(Armor armor);

        /** Access inventory
         * \return The current value of inventory
         */
        Inventory Getinventory() const;

        /** Set inventory
         * \param val New value to set
         */
        void Setinventory(Inventory inventory);

        /** Access spells
         * \return The current value of spells
         */
        Spells Getspells() const;

        /** Set spells
         * \param val New value to set
         */
        void Setspells(Spells spells);

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

         void damageReceived(int dmg);

    protected:


};

#endif // PLAYER_H
