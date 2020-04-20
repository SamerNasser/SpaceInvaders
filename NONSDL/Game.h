//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_GAME_H
#define SPACEINVADERSV2_GAME_H

#include "AFactory.h"

namespace NONSDL {
    class Game {
    private:
        //constructors
        Game(AFactory *);

        //copy constructor
        //Game(const Game &c);

        //assignment operator
        //Game &operator=(const Game &c);

        static Game *game; //Dit moet static zijn, omdat we er niet meer dan 1 van mogen aanmaken
        AFactory *afact;

    public:
        //destructor
        ~Game();

        void run();

        static Game *
        gameInstance(AFactory *); //Dit moet static zijn omdat we de methode al moeten kunnen oproepen alvorens
        // er een object van gemaakt is, want de constructor is private.
    };
}


#endif //SPACEINVADERSV2_GAME_H
