//
// Created by samer on 21/04/2020.
//

#ifndef SPACEINVADERSV2_BONUSENTITY_H
#define SPACEINVADERSV2_BONUSENTITY_H


#include "Entity.h"

namespace NONSDL {
    class BonusEntity : public Entity { 
    public:
        //constructor
        BonusEntity(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~BonusEntity();

        //copy constructor
        //BonusEntity(const BonusEntity &c);

        //assignment operator
        //BonusEntity &operator=(const BonusEntity &c);

        //make visible
        virtual void visualize(Window* win) = 0;

        virtual void disappear() = 0;
    };
}

#endif //SPACEINVADERSV2_BONUSENTITY_H
