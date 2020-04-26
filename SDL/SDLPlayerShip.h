//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_SDLPLAYERSHIP_H
#define SPACEINVADERSV2_SDLPLAYERSHIP_H
#include "../NONSDL/PlayerShip.h"
#include "SDLWindow.h"

namespace SDL {
    class SDLPlayerShip : public NONSDL::PlayerShip{
    public:
        //constructor
        SDLPlayerShip(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        ~SDLPlayerShip();

        //make visible
        void visualize(NONSDL::Window* win);

    };
}


#endif //SPACEINVADERSV2_SDLPLAYERSHIP_H
