//
// Created by samer on 21/04/2020.
//

#ifndef SPACEINVADERSV2_PBONUS_H
#define SPACEINVADERSV2_PBONUS_H


#include "BonusEntity.h"

namespace NONSDL {
    class PBonus : public BonusEntity {
    public:
        //constructor
        PBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~PBonus();

        //make visible
        virtual void visualize(Window* win) = 0;

        virtual void disappear() = 0;
    };
}


#endif //SPACEINVADERSV2_PBONUS_H
