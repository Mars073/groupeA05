#ifndef SPELLS_H
#define SPELLS_H
#include <vector>
#include <fstream>
#include <algorithm>
#include "Magic.h"

class Spells
{
    private:
        std::vector<Magic*>spellsHeld; //list of magic ingame
        std::vector<Magic*>everySpells; //list of every magic from the file

    public:
        /** Default constructor */
        Spells();
        /** Default destructor */
        virtual ~Spells();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Spells(const Spells& s);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Spells& operator=(const Spells& s);

        /** add a magic in the list of spells ingame not in the file
         *  \param the magic to add ingame
         */
        void addMagic(Magic *magic);

        /** add a magic in the list of spells ingame not in the file
         *  \param the name of the magic from the file to add ingame
         */
        void addMagic(std::string magicName);

        /** add a magic in the file not in the list of spells ingame
         *  \param the magic to add in the file
         */
        void addMagicInFile(Magic *magic);

        int indexOf(Magic*) const;

        int indexOfEverySpells(Magic*) const;

        std::vector<Magic*> GetspellsHeld() const;

        std::vector<Magic*> GeteverySpells() const;

        virtual std::string str() const;

        /** read the file "spells.txt" in "data/lists" and add them as magic in the everySpells list
         *
         */
        void readFromFile();

        /** write in the file "spells.txt" in "data/lists"
         *
         */
        void writeInFile();

        /** return the magic with the name in the argument from the file
         *  \param the name of the magic to return
         */
        Magic* getOneMagic(std::string name);

        /** return the magic with the name in the argument ingame
         *  \param the name of the magic to return
         */
        Magic* getOneMagicInGame(std::string name);

        /** allow to change the attributes of a magic and write it in the file
         *  \param nameMagic the name of the magic to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name or "damage" for its base damage
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameMagic,std::string nameAttribute,std::string val);

        /** allow to change the attributes of a magic and write it in the file
         *  \param nameMagic the name of the magic to change its attributes
         *  \param nameAttribute the name of the attribute. It can be : "name" for its name or "damage" for its base damage
         *  \param val the new value that will replace the current one
         */
        void changeAttribute(std::string nameMagic,std::string nameAttribute,int val);

        /** delete a magic from the list ingame
         *  \param the name of the magic to delete
         */
        void deleteMagic(std::string nameMagic);

        /** delete a magic from the list in the file
         *  \param the name of the magic to delete
         */
        void deleteMagicInFile(std::string nameMagic);

    protected:


};

#endif // SPELLS_H
