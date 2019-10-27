#ifndef NPC_H
#define NPC_H

#include <Character.h>


class Npc : public Character
{
    private:

    public:
        /** Default constructor */
        Npc(std::string charaName);
        /** Default destructor */
        virtual ~Npc();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Npc(const Npc& n);

        Npc& operator=(const Npc& n);

        Npc* clone() const override;

    protected:


};

#endif // NPC_H
