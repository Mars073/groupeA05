#ifndef BESTIARY_H
#define BESTIARY_H
#include "Monster.h"
#include <vector>
#include <fstream>
#include <algorithm>

class Bestiary
{
    private:
        std::vector<Monster*>bestiary;
    public:
        /** Default constructor */
        Bestiary();
        /** Default destructor */
        virtual ~Bestiary();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Bestiary(const Bestiary& b);

        Bestiary& operator=(const Bestiary& b);

        /** add a monster in the bestiary
         *  \param the monster to add in the bestiary
         */
        void addMonster(Monster *monster);

        int indexOf(Monster*) const;

        /** return the all bestiary
         *
         */
        std::vector<Monster*> Getbestiary() const;

        /** write every information about the bestiary
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
        Monster* getOneMonster(std::string name);

        /** allow to change the attributes of a monster and write it in the file that contains all monsters
         *  \param nameMonster the name of the monster to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name, "hp" for its hp, "mp" for its mp, "atk" for its atk,
         *  "mag" for its magical power, "def" for its def, "level" for its level, "money" for its money held or "exp" for its exp held
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameMonster,std::string nameAttribute,std::string val);

        /** allow to change the attributes of a monster and write it in the file that contains all monsters
         *  \param nameMonster the name of the monster to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name, "hp" for its hp, "mp" for its mp, "atk" for its atk,
         *  "mag" for its magical power, "def" for its def, "level" for its level, "money" for its money held or "exp" for its exp held
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameMonster,std::string nameAttribute,int val);

        /** delete a monster from the list
         *  \param the name of the monster to delete
         */
        void deleteMonster(std::string nameMonster);

    protected:


};

#endif // BESTIARY_H
