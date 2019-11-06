#ifndef COOLDOWN_H
#define COOLDOWN_H

#include "iostream"
#include <SFML/System.hpp>


class Cooldown
{
    public:
        /** Default constructor */
        Cooldown();
        /** Default destructor */
        virtual ~Cooldown();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Cooldown(const Cooldown& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Cooldown& operator=(const Cooldown& other);
        static bool isTimePassed(float &valActuel,float maxVal,bool isCooldown);

    protected:

    private:
        sf::Clock clock;
        sf::Time elapsed;
};

#endif // COOLDOWN_H
