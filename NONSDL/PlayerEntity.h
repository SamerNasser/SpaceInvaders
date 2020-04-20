//
// Created by samer on 30/03/2020.
//

#ifndef SPACEINVADERSV2_PLAYERENTITY_H
#define SPACEINVADERSV2_PLAYERENTITY_H
#include "Entity.h"

namespace NONSDL {
    class PlayerEntity : public Entity {
    public:
        //constructor
        PlayerEntity(float xPos, float yPos, float w, float h, float xSpeed, float ySpeed);

        //destructor
        virtual ~PlayerEntity();

        //make visible
        virtual void visualize() = 0;
    };
}


#endif //SPACEINVADERSV2_PLAYERENTITY_H
