//
// Created by samer on 21/04/2020.
//

#ifndef SPACEINVADERSV2_SDLNBONUS_H
#define SPACEINVADERSV2_SDLNBONUS_H


#include "../NONSDL/BonusEntity.h"

namespace SDL {
    class SDLNBonus : public NONSDL::BonusEntity{
    public:
        // Constructor.
        SDLNBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        ~SDLNBonus();

        // Methods.
        void visualize(NONSDL::Window* win);

        void disappear();

    };
}



#endif //SPACEINVADERSV2_SDLNBONUS_H
