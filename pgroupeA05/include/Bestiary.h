#ifndef BESTIARY_H
#define BESTIARY_H
#include "Monster.h"
#include <list>
#include <fstream>

class Bestiary
{
    private:
        std::list<Monster*>bestiary;
    public:
        /** Default constructor */
        Bestiary();
        /** Default destructor */
        virtual ~Bestiary();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Bestiary(const Bestiary& b);

        /** add a monster in the bestiary
         *  \param the monster to add in the bestiary
         */
        void addMonster(Monster *monster);

        /** return the all bestiary
         *
         */
        std::list<Monster*> Getbestiary() const;

        /** write every information about the bestiary
         *
         */
        virtual std::string str() const;

        /** read the file "bestiary.txt" in "data/lists" and add them as monsters in the bestiary
         *
         */
        void readFromFile();

        /** write in the file "bestiary.txt" in "data/lists"
         * \param the monster to add in the file
         */
        void writeInFile(Monster* monster);

        /** return the monster with the name in the argument
         *  \param the name of the monster to return
         */
        Monster* getOneMonster(std::string name);

    protected:


};

#endif // BESTIARY_H
