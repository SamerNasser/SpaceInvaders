//
// Created by samer on 21/04/2020.
//

#ifndef SPACEINVADERSV2_NBONUS_H
#define SPACEINVADERSV2_NBONUS_H


#include "BonusEntity.h"

namespace NONSDL {
    class NBonus : public BonusEntity {
    public:
        //constructor
        NBonus(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~NBonus();

        //make visible
        virtual void visualize(Window* win) = 0;

        virtual void disappear() = 0;
    };
}


#endif //SPACEINVADERSV2_NBONUS_H
