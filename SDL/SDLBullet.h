//
// Created by samer on 09/04/2020.
//

#ifndef SPACEINVADERSV2_SDLBULLET_H
#define SPACEINVADERSV2_SDLBULLET_H

#include "../NONSDL/Bullet.h"
#include "SDLWindow.h"

namespace SDL {
    class SDLBullet : public NONSDL::Bullet{
    public:
        // Constructor.
        SDLBullet(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        ~SDLBullet();

        // Make visible.
        void visualize(NONSDL::Window* win);

        void disappear();

    };
}



#endif //SPACEINVADERSV2_SDLBULLET_H
