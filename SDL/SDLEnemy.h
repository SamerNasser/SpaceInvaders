//
// Created by samer on 11/04/2020.
//

#ifndef SPACEINVADERSV2_SDLENEMY_H
#define SPACEINVADERSV2_SDLENEMY_H

#include "../NONSDL/Enemy.h"
#include "SDLWindow.h"

namespace SDL {
    class SDLEnemy : public NONSDL::Enemy{
    public:
        // Constructor.
        SDLEnemy(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        ~SDLEnemy();

        // Methods.
        void visualize(NONSDL::Window* win);

        void switchDirection();

        void shiftDown();

    };
}


#endif //SPACEINVADERSV2_SDLENEMY_H
