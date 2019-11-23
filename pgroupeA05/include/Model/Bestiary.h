// *** ADDED BY HEADER FIXUP ***
#include <ctime>
// *** END ***
#ifndef BESTIARY_H
#define BESTIARY_H
#include "Monster.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>
#include "Inventory.h"

class Bestiary
{
    private:
        std::vector<Monster*>bestiary; //!< Member variable "bestiary"
        Inventory* inventory; //!< Member variable "inventory"
    public:
        /** Default constructor */
        Bestiary();

        /** Default destructor */
        virtual ~Bestiary();

        /** Copy constructor
         *  \param other Object to copy from
         */
        Bestiary(const Bestiary& b);

        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Bestiary& operator=(const Bestiary& b);

        /** add a monster in the bestiary and in the file
         *  \param the monster to add in the bestiary
         */
        void addMonster(Monster *monster);

        /** \brief Allow to find the index of the Monster in the list bestiary
         *
         * \param the Monster to find the index
         * \return the index of the Monster in the list bestiary
         */
        int indexOf(Monster*) const;

        /** Access bestiary
         * \return The current value of bestiary
         */
        std::vector<Monster*> Getbestiary() const;

        /** \brief Display all the informations about the Bestiary
         *
         * \return virtual std::string the informations
         *
         */
        virtual std::string str() const;

        /** read the file "bestiary.txt" in "data/lists" and add them as monsters in the bestiary
         *
         */
        void readFromFile();

        /** write in the file "bestiary.txt" in "data/lists"
         *
         */
        void writeInFile();

        /** return the monster with the name in the argument
         *  \param the name of the monster to return
         */
        Monster* getOneMonster(std::string name) const;

        /** allow to change the attributes of a monster and write it in the file that contains all monsters
         *  \param nameMonster the name of the monster to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name, "hp" for its hp, "mp" for its mp, "atk" for its atk,
         *  "mag" for its magical power, "def" for its def, "level" for its level or "exp" for its exp held
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameMonster,std::string nameAttribute,std::string val);

        /** allow to change the attributes of a monster and write it in the file that contains all monsters
         *  \param nameMonster the name of the monster to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name, "hp" for its hp, "mp" for its mp, "atk" for its atk,
         *  "mag" for its magical power, "def" for its def, "level" for its level or "exp" for its exp held
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameMonster,std::string nameAttribute,int val);

        /** delete a monster from the list
         *  \param the name of the monster to delete
         */
        void deleteMonster(std::string nameMonster);

        /** \brief Choose a random monster in the list bestiary
         *
         * \return a Monster
         *
         */
        Monster* getOneRandomMonster() const;

    protected:


};

#endif // BESTIARY_H
