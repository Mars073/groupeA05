#include "Npc.h"

Npc::Npc(std::string charaName):Character(charaName)
{
    //ctor
}

Npc::~Npc()
{
    //dtor
}

Npc::Npc(const Npc& n):Character(n)
{
    //copy ctor
}

Npc& Npc::operator=(const Npc& n){
    if(this!=&n){

    }
    return *this;
}
