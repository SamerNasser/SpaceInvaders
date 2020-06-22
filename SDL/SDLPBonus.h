//
// Created by samer on 21/04/2020.
//

#ifndef SPACEINVADERSV2_SDLPBONUS_H
#define SPACEINVADERSV2_SDLPBONUS_H

#include "../NONSDL/BonusEntity.h"


namespace SDL {
    class SDLPBonus : public NONSDL::BonusEntity{
    public:
        // Constructor.
        SDLPBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        // Destructor.
        ~SDLPBonus();

        // Methods
        void visualize(NONSDL::Window* win);

        void disappear();

    };
}


#endif //SPACEINVADERSV2_SDLPBONUS_H
