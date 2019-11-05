#include "Cooldown.h"

Cooldown::Cooldown()
{
    //ctor
}

Cooldown::~Cooldown()
{
    //dtor
}

Cooldown::Cooldown(const Cooldown& other)
{
    //copy ctor
}

Cooldown& Cooldown::operator=(const Cooldown& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
bool Cooldown::isTimePassed(float &valActuel,float maxVal,bool isCooldown)
{

        if(isCooldown == true)
        {
            sf::Clock cl;
            sf::Time elapsed = cl.getElapsedTime();
            valActuel-=elapsed.asSeconds();
            cl.restart();
            if(valActuel<0)
            {
                valActuel = maxVal;
                return true;
            }
        }
        return false;
}
