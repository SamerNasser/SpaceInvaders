//
// Created by samer on 12/04/2020.
//

#ifndef SPACEINVADERSV2_SDLPROJECTILE_H
#define SPACEINVADERSV2_SDLPROJECTILE_H


#include "../NONSDL/Projectile.h"
#include "SDLWindow.h"

namespace SDL {
    class SDLProjectile : public NONSDL::Projectile{
    public:
        // Constructor.
        SDLProjectile(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed, SDL::SDLWindow* win);

        // Destructor.
        ~SDLProjectile();

        // Make visible.
        void visualize();

    private:
        SDLWindow* window;

    };
}


#endif //SPACEINVADERSV2_SDLPROJECTILE_H
