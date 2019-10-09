#ifndef FightScene_H
#define FightScene_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "WindowsFight.h"
#include "vector"
#include "iostream"
#include "IstrategyBtn.h"


class FightScene
{
    public:
        FightScene();
        virtual ~FightScene();
        void fight();

    protected:

    private:
};

#endif // FightScene_H
